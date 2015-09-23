#include <project.h>
#include <stdlib.h>
#include "cv.h"

//Framebuffer: holds a single image in UYVY format
//organised as 144 rows of 88 pixel pairs
//each pixel pair has 4 components: U, Y0, V, Y1
//uint8 Camera_framebuffer[144][88][4];

int takePhoto() {
    Camera_SyncFrame();
	Camera_GetFrame(); // Start frame capture
    Camera_SyncFrame(); // Wait until frame is fully captued
    
    return 0;
}

uint8 * parsePhoto() {
//    Lcd_PosPrintString(0, 0, "here");
    uint8 * plan = (uint8 *) malloc(sizeof(uint8) * ROWS);    
    
    // YUV -> RGB
//    R = Y+V
//    G = Y-U-V
//    B = Y+U
    uint8 h, w;
    //  0, 1, 2;
    uint8 u, v, y;
    
    for (h = 0; h < IMG_H; h++) {
        for (w = 0; w < IMG_W; w++) {
            u = Camera_framebuffer[h][w][0];
            v = Camera_framebuffer[h][w][1];
            y = Camera_framebuffer[h][w][2];
            // R
            Camera_framebuffer[h][w][0] = y + v;
            // G
            Camera_framebuffer[h][w][1] = y - u - v;
            // B
            Camera_framebuffer[h][w][2] = y + u;
            // Grey
            Camera_framebuffer[h][w][3] = (Camera_framebuffer[h][w][0] + Camera_framebuffer[h][w][1] + Camera_framebuffer[h][w][2]) / 3;
        }
    }
    
    // Create Img Diff arrays
    for (h = 0; h < IMG_H; h++) {
        for (w = 0; w < IMG_W; w++) {
            Camera_framebuffer[h][w][0] = Camera_framebuffer[h][w][0] - Camera_framebuffer[h][w][3];
            Camera_framebuffer[h][w][1] = 2*Camera_framebuffer[h][w][1] - Camera_framebuffer[h][w][3];
            Camera_framebuffer[h][w][2] = Camera_framebuffer[h][w][2] - Camera_framebuffer[h][w][3];
        }
    }
    
    // Thresholding
    for (h = 0; h < IMG_H; h++) {
        for (w = 0; w < IMG_W; w++) {
            // Red
            if (Camera_framebuffer[h][w][0] > THRESHOLD_R)
                Camera_framebuffer[h][w][0] = 1;
            else
                Camera_framebuffer[h][w][0] = 0;
            
            // Green
            if (Camera_framebuffer[h][w][1] > THRESHOLD_G)
                Camera_framebuffer[h][w][1] = 1;
            else
                Camera_framebuffer[h][w][1] = 0;
            
            // Blue
            if (Camera_framebuffer[h][w][2] > THRESHOLD_B)
                Camera_framebuffer[h][w][2] = 1;
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
    
    while (1) {
        if (i > IMG_H)
            break;
        
        if (Camera_framebuffer[i][halfWidth][1] == 0) {
            currentHeight += 1;
            i++;
        }
        else if (Camera_framebuffer[i+1][halfWidth][1] == 0) {
            currentHeight += 2;
            i += 1;
        }
        else if (Camera_framebuffer[i+2][halfWidth][1] == 0) {
            currentHeight += 3;
            i += 2;
        }
        else {
            if (currentHeight > maxHeight)
                maxHeight = currentHeight;
            
            currentHeight = 0;
            i++;
        }
    }
    uint8 boxHeight = maxHeight / ROWS;
//    Lcd_PrintDecUint16(maxHeight);
    
    i = 0;
    while (1) {
        if (i > IMG_H)
            break;
        
        if (Camera_framebuffer[halfHeight][i][1] == 0) {
            currentWidth += 1;
            i++;
        }
        else if (Camera_framebuffer[halfHeight][i+1][1] == 0) {
            currentWidth += 2;
            i += 1;
        }
        else if (Camera_framebuffer[halfHeight][i+2][1] == 0) {
            currentWidth += 3;
            i += 2;
        }
        else {
            if (currentWidth > maxWidth)
                maxHeight = currentWidth;
            
            currentWidth = 0;
            i++;
        }
    }
//    uint8 boxWidth = maxWidth;
    
    
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
    uint8 rowUpTo = 1;
    uint8 mode = 0;
    uint8 numBoxes = 0;
    
    // Main parse
    while (1) {
        // Loop condition
        j++;
        if (j > hPos + maxHeight)
            break;
        
        // Switch on colour mode
        switch (mode) {
            case RED:
                if (Camera_framebuffer[j][halfWidth][3] == cRED) {
                    maxLength++;
                }
                else if (Camera_framebuffer[j+1][halfWidth][3] == cRED) {
                    maxLength += 2;
                    i++;
                }
                else if (Camera_framebuffer[j+2][halfWidth][3] == cRED) {
                    maxLength += 3;
                    i += 2;
                }
                else {
                    if (maxLength > MIN_BOX_HEIGHT) {
                        numBoxes = maxLength / boxHeight;
                        
                        if (numBoxes == 2) {
                            plan[rowUpTo] = RED;
                            plan[rowUpTo+1] = RED;
                            rowUpTo += 2;
                        }
                        else if (numBoxes == 3) {
                            plan[rowUpTo] = RED;
                            plan[rowUpTo+1] = RED;
                            plan[rowUpTo+2] = RED;
                            rowUpTo += 3;
                        }
                        else {
                            plan[rowUpTo] = RED;
                            rowUpTo++;
                        }
                    }
                    
                    maxLength = 0;
                    if (Camera_framebuffer[i][halfWidth][3] == cGREEN)
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
                    i++;
                }
                else if (Camera_framebuffer[j+2][halfWidth][3] == cGREEN) {
                    maxLength += 3;
                    i += 2;
                }
                else {
                    if (maxLength > MIN_BOX_HEIGHT) {
                        numBoxes = maxLength / boxHeight;
                        
                        if (numBoxes == 2) {
                            plan[rowUpTo] = GREEN;
                            plan[rowUpTo+1] = GREEN;
                            rowUpTo += 2;
                        }
                        else if (numBoxes == 3) {
                            plan[rowUpTo] = GREEN;
                            plan[rowUpTo+1] = GREEN;
                            plan[rowUpTo+2] = GREEN;
                            rowUpTo += 3;
                        }
                        else {
                            plan[rowUpTo] = GREEN;
                            rowUpTo++;
                        }
                    }
                    
                    maxLength = 0;
                    if (Camera_framebuffer[i][halfWidth][3] == cRED)
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
                    i++;
                }
                else if (Camera_framebuffer[j+2][halfWidth][3] == cBLUE) {
                    maxLength += 3;
                    i += 2;
                }
                else {
                    if (maxLength > MIN_BOX_HEIGHT) {
                        numBoxes = maxLength / boxHeight;
                        
                        if (numBoxes == 2) {
                            plan[rowUpTo] = BLUE;
                            plan[rowUpTo+1] = BLUE;
                            rowUpTo += 2;
                        }
                        else if (numBoxes == 3) {
                            plan[rowUpTo] = BLUE;
                            plan[rowUpTo+1] = BLUE;
                            plan[rowUpTo+2] = BLUE;
                            rowUpTo += 3;
                        }
                        else {
                            plan[rowUpTo] = BLUE;
                            rowUpTo++;
                        }
                    }
                    
                    maxLength = 0;
                    if (Camera_framebuffer[i][halfWidth][3] == cRED)
                        mode = RED;
                    else
                        mode = GREEN;
                    maxLength++;
                }
                break;
                
            default: // Initial
                if (Camera_framebuffer[i][halfWidth][3] == cRED)
                    mode = RED;
                else if (Camera_framebuffer[i][halfWidth][3] == cGREEN)
                    mode = GREEN;
                else
                    mode = BLUE;
                
                maxLength++;
                break;
        }
    }
    
//    Lcd_PosPrintString(0, 0, "here");
    return plan; // TODO: Check if returning the right thing
}

uint8 * readPlanWithCamera() {
//    int * plan = (int *) malloc(sizeof(int) * ROWS);
    
    takePhoto();
    return parsePhoto();
    
//    plan[0] = 1;
//    plan[1] = 2;
//    plan[2] = 3;
//    
//    return plan;
}