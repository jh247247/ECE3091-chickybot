#include <project.h>
#include <stdlib.h>
#include "cv.h"

//Framebuffer: holds a single image in UYVY format
//organised as 144 rows of 88 pixel pairs
//each pixel pair has 4 components: U, Y0, V, Y1
//uint8 Camera_framebuffer[144][88][4];

uint16 takePhoto() {
    Camera_SyncFrame();
	Camera_GetFrame(); // Start frame capture
    Camera_SyncFrame(); // Wait until frame is fully captued
    
    return 0;
}

uint16 * parsePhoto() {
    
    // Init plan
    uint16 * plan = (uint16 *) malloc(sizeof(uint16) * ROWS);
    
    uint8 r;
    for (r = 0; r < ROWS; r++) {
        plan[r] = NONE;
    }
    
    
    // YUV -> RGB
    //    R = Y+V
    //    G = Y-U-V
    //    B = Y+U
    uint8 h, w;
    uint16 u, v, y;
    uint16 red, green, blue;
    
    for (h = 0; h < IMG_H; h++) {
        for (w = 0; w < IMG_W; w++) {
            u = (uint16) Camera_framebuffer[h][w][0];
            y = (uint16) Camera_framebuffer[h][w][1];
            v = (uint16) Camera_framebuffer[h][w][2];
            // R
            red = y + v;
            Camera_framebuffer[h][w][0] = (uint8) red;
            // G
            green = y - u - v;
            Camera_framebuffer[h][w][1] = (uint8) green;
            // B
            blue = y + u;
            Camera_framebuffer[h][w][2] = (uint8) blue;
            // Grey
            Camera_framebuffer[h][w][3] = (uint8) (red + blue + green) / 3;
        }
    }
    
    //sendCameraDataOverUsb();
    
    // Create Img Diff arrays
    for (h = 0; h < IMG_H; h++) {
        for (w = 0; w < IMG_W; w++) {
            Camera_framebuffer[h][w][0] = (uint8) (((uint16) Camera_framebuffer[h][w][0]) - ((uint16) Camera_framebuffer[h][w][3]));
            Camera_framebuffer[h][w][1] = (uint8) (((uint16) Camera_framebuffer[h][w][1]) - ((uint16) Camera_framebuffer[h][w][3]));
            Camera_framebuffer[h][w][2] = (uint8) (((uint16) Camera_framebuffer[h][w][2]) - ((uint16) Camera_framebuffer[h][w][3]));
        }
    }
    
    
    // Thresholding
    int numRed = 0, numGreen = 0, numBlue = 0;
    for (h = 0; h < IMG_H; h++) {
        for (w = 0; w < IMG_W; w++) {
            // Red
            if (Camera_framebuffer[h][w][0] > THRESHOLD_R) {
                Camera_framebuffer[h][w][0] = 1;
                numRed++;
            }
            else
                Camera_framebuffer[h][w][0] = 0;
            
            // Green
            if (Camera_framebuffer[h][w][1] > THRESHOLD_G) {
                Camera_framebuffer[h][w][1] = 1;
                numGreen++;
            }
            else
                Camera_framebuffer[h][w][1] = 0;
            
            // Blue
            if (Camera_framebuffer[h][w][2] > THRESHOLD_B) {
                Camera_framebuffer[h][w][2] = 1;
                numBlue++;
            }
            else
                Camera_framebuffer[h][w][2] = 0;
        }
    }
    
    // Find box dims
    
    // Note: Use imgG_Bin to find bounds
    // Go down centre until find 0    v
    uint8 maxHeight = 0;
    uint8 currentHeight = 0;
    uint8 maxWidth = 0;
    uint8 currentWidth = 0;
    uint8 halfHeight = IMG_H / 2;
    uint8 halfWidth = IMG_W / 2;
    uint8 i = 0;
    
    // Find max height
    while (1) {
        if (i > IMG_H)
            break;
        
        if (Camera_framebuffer[i][halfWidth][1] == 0) {
            currentHeight++;
            i++;
        }
        else if (Camera_framebuffer[i+1][halfWidth][1] == 0) {
            currentHeight += 2;
            i += 2;
        }
        else if (Camera_framebuffer[i+2][halfWidth][1] == 0) {
            currentHeight += 3;
            i += 3;
        }
        else {
            if (currentHeight > maxHeight)
                maxHeight = currentHeight;
            
            currentHeight = 0;
            i++;
        }
    }
    
    // Find max width
    i = 0;
    while (1) {
        if (i > IMG_W)
            break;
        
        if (Camera_framebuffer[halfHeight][i][1] == 0) {
            currentWidth++;
            i++;
        }
        else if (Camera_framebuffer[halfHeight][i+1][1] == 0) {
            currentWidth += 2;
            i += 2;
        }
        else if (Camera_framebuffer[halfHeight][i+2][1] == 0) {
            currentWidth += 3;
            i += 3;
        }
        else {
            if (currentWidth > maxWidth)
                maxWidth = currentWidth;
            
            currentWidth = 0;
            i++;
        }
    }
    
    // Debug output
    Lcd_ClearDisplay();
    Lcd_Position(0,0);
    Lcd_PrintNumber(maxHeight);
    Lcd_PosPrintString(0,5,"x");
    Lcd_Position(0,7);
    Lcd_PrintNumber(maxWidth);
    
    if (maxWidth > maxHeight) {
        Lcd_ClearDisplay();
        Lcd_Position(0,0);
        Lcd_PrintString("W>H Check orient");
        
        return plan;
    }
    
    
    // Start at centre, head toward top-left
    uint8 hPos = halfHeight;
    uint8 wPos = halfWidth;
    while (1) {
        if (Camera_framebuffer[hPos-1][wPos-1][1] == 0) {
            hPos = hPos-1;
            wPos = wPos-1;
        }
        else if (Camera_framebuffer[hPos-1][wPos][1] == 0) {
            hPos = hPos-1;
        }
        else if (Camera_framebuffer[hPos][wPos-1][1] == 0) {
            wPos = wPos-1;
        }
        else if (Camera_framebuffer[hPos-1][wPos+1][1] == 0) {
            hPos = hPos-1;
            wPos = wPos+1;
        }
        else
            break;
    }
    
    // Err msg if cannot find plan
    if (hPos == 255) {
        Lcd_ClearDisplay();
        Lcd_Position(0,0);
        Lcd_PrintString("Cannot find plan.");
        
        plan[0] = numRed / (IMG_H*IMG_W) * 100;
        plan[1] = numGreen / (IMG_H*IMG_W) * 100;
        plan[2] = numBlue / (IMG_H*IMG_W) * 100;
        
        return plan;
    }
    
    // Create single array
    for (h = 0; h < IMG_H; h++) {
        for (w = 0; w < IMG_W; w++) {
            Camera_framebuffer[h][w][3] = (((2*(!Camera_framebuffer[h][w][1])) + 3*((!Camera_framebuffer[h][w][1]) & Camera_framebuffer[h][w][2])) + ((!Camera_framebuffer[h][w][1]) & Camera_framebuffer[h][w][0]));
        }
    }
    // NOTE: In imgAll, R=3, G=2, B=5, 0=ignore
    const uint8 cRED = 3, cGREEN = 2, cBLUE = 5;
    
    
    // Vars for main parse
    uint8 j = hPos;
    uint8 maxLength = 0;
    uint8 rowUpTo = 0;
    uint8 mode = 0;
    
    // Main parse
    while (1) {
        // Loop condition
        j++;
        if (j > hPos + maxHeight)
            break;
        if (rowUpTo >= ROWS)
            break;
        
        // Switch on colour mode
        switch (mode) {
            case RED:
                if (Camera_framebuffer[j][halfWidth][3] == cRED) {
                    maxLength++;
                }
                else if (Camera_framebuffer[j+1][halfWidth][3] == cRED) {
                    maxLength += 2;
                    j++;
                }
                else if (Camera_framebuffer[j+2][halfWidth][3] == cRED) {
                    maxLength += 3;
                    j += 2;
                }
                else {
                    if (maxLength > MIN_BOX_HEIGHT) {
                        plan[rowUpTo] = RED;
                        rowUpTo++;
                    }
                    
                    maxLength = 0;
                    if (Camera_framebuffer[j][halfWidth][3] == cGREEN)
                        mode = GREEN;
                    else
                        mode = BLUE;
                    maxLength++;
                }
                break;
            
            case GREEN:
                if (Camera_framebuffer[j][halfWidth][3] == cGREEN) {
                    maxLength++;
                }
                else if (Camera_framebuffer[j+1][halfWidth][3] == cGREEN) {
                    maxLength += 2;
                    j++;
                }
                else if (Camera_framebuffer[j+2][halfWidth][3] == cGREEN) {
                    maxLength += 3;
                    j += 2;
                }
                else {
                    if (maxLength > MIN_BOX_HEIGHT) {
                        plan[rowUpTo] = GREEN;
                        rowUpTo++;
                    }
                    
                    maxLength = 0;
                    if (Camera_framebuffer[j][halfWidth][3] == cRED)
                        mode = RED;
                    else
                        mode = BLUE;
                    maxLength++;
                }
                break;
            
            case BLUE:
                if (Camera_framebuffer[j][halfWidth][3] == cBLUE) {
                    maxLength++;
                }
                else if (Camera_framebuffer[j+1][halfWidth][3] == cBLUE) {
                    maxLength += 2;
                    j++;
                }
                else if (Camera_framebuffer[j+2][halfWidth][3] == cBLUE) {
                    maxLength += 3;
                    j += 2;
                }
                else {
                    if (maxLength > MIN_BOX_HEIGHT) {
                        plan[rowUpTo] = BLUE;
                        rowUpTo++;
                    }
                    
                    maxLength = 0;
                    if (Camera_framebuffer[j][halfWidth][3] == cRED)
                        mode = RED;
                    else
                        mode = GREEN;
                    maxLength++;
                }
                break;
                
            default: // Initial
                if (Camera_framebuffer[j][halfWidth][3] == cRED)
                    mode = RED;
                else if (Camera_framebuffer[j][halfWidth][3] == cGREEN)
                    mode = GREEN;
                else
                    mode = BLUE;
                
                maxLength++;
                break;
        }
    }
    
    return plan;
}

uint16 * readPlanWithCamera() {
    takePhoto();
    return parsePhoto();
}

void sendCameraDataOverUsb() {
    uint16 i;
	for(i=0;i<sizeof Camera_framebuffer;i+=64)
	{
		while(!USB_CDCIsReady()); //wait until USB is ready
		USB_PutData((uint8*)Camera_framebuffer+i,64); //send next 64 byte packet (maximum size)
	}
}