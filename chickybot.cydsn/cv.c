#include <project.h>
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

int * parsePhoto() {
//    Lcd_PosPrintString(0, 0, "here");
    int plan[ROWS];
    
    // Vars
    int imgR[IMG_H][IMG_W];
    int imgG[IMG_H][IMG_W];
    int imgB[IMG_H][IMG_W];
    int imgR_Diff[IMG_H][IMG_W];
    int imgG_Diff[IMG_H][IMG_W];
    int imgB_Diff[IMG_H][IMG_W];
    int imgR_Bin[IMG_H][IMG_W];
    int imgG_Bin[IMG_H][IMG_W];
    int imgB_Bin[IMG_H][IMG_W];
    int imgGrey[IMG_H][IMG_W];
    
    // YUV -> RGB
//    R = Y+V
//    G = Y-U-V
//    B = Y+U
    int h, w;
    int U = 0, Y0 = 1, V = 2, Y1 = 3;
    
    for (h = 0; h < IMG_H; h++) {
        for (w = 0; w < IMG_W; w++) {
            if (w % 2 == 0) {
                imgR[h][w] = Camera_framebuffer[h][w/2][Y0] + Camera_framebuffer[h][w/2][V];
                imgG[h][w] = Camera_framebuffer[h][w/2][Y0] - Camera_framebuffer[h][w/2][U] - Camera_framebuffer[h][w/2][V];
                imgB[h][w] = Camera_framebuffer[h][w/2][Y0] + Camera_framebuffer[h][w/2][U];
            }
            else {
                imgR[h][w] = Camera_framebuffer[h][w/2][Y1] + Camera_framebuffer[h][w/2][V];
                imgG[h][w] = Camera_framebuffer[h][w/2][Y1] - Camera_framebuffer[h][w/2][U] - Camera_framebuffer[h][w/2][V];
                imgB[h][w] = Camera_framebuffer[h][w/2][Y1] + Camera_framebuffer[h][w/2][U];
            }
        }
    }
    
    // Create Grey array
    for (h = 0; h < IMG_H; h++) {
        for (w = 0; w < IMG_W; w++) {
            imgGrey[h][w] = (imgR[h][w] + imgG[h][w] + imgB[h][w]) / 3;
        }
    }
    
    // Create Img Diff arrays
    for (h = 0; h < IMG_H; h++) {
        for (w = 0; w < IMG_W; w++) {
            imgR_Diff[h][w] = imgR[h][w] - imgGrey[h][w];
            imgG_Diff[h][w] = 2*imgG[h][w] - imgGrey[h][w];
            imgB_Diff[h][w] = imgB[h][w] - imgGrey[h][w];
        }
    }
    
    // Thresholding
    for (h = 0; h < IMG_H; h++) {
        for (w = 0; w < IMG_W; w++) {
            // Red
            if (imgR_Diff[h][w] > THRESHOLD_R)
                imgR_Bin[h][w] = 1;
            else
                imgR_Bin[h][w] = 0;
            
            // Green
            if (imgG_Diff[h][w] > THRESHOLD_G)
                imgG_Bin[h][w] = 1;
            else
                imgG_Bin[h][w] = 0;
            
            // Blue
            if (imgB_Diff[h][w] > THRESHOLD_B)
                imgB_Bin[h][w] = 1;
            else
                imgB_Bin[h][w] = 0;
        }
    }
    
//    // Find box dims
//    
//    // Note: Use imgG_Bin to find bounds
//    // Go down centre until find 0    v
//    int maxHeight = 0;
//    int currentHeight = 0;
//    int maxWidth = 0;
//    int currentWidth = 0;
//    int halfHeight = IMG_H / 2;
//    int halfWidth = IMG_W / 2;
//    int i = 0;
//
//    while (1) {
//        if (i > IMG_H)
//            break;
//        
//        if (imgG_Bin[i][halfWidth] == 0) {
//            currentHeight += 1;
//            i++;
//        }
//        else if (imgG_Bin[i+1][halfWidth] == 0) {
//            currentHeight += 2;
//            i += 1;
//        }
//        else if (imgG_Bin[i+2][halfWidth] == 0) {
//            currentHeight += 3;
//            i += 2;
//        }
//        else {
//            if (currentHeight > maxHeight)
//                maxHeight = currentHeight;
//            
//            currentHeight = 0;
//            i++;
//        }
//    }
//    int boxHeight = maxHeight / ROWS;
//    
//    i = 0;
//    while (1) {
//        if (i > IMG_H)
//            break;
//        
//        if (imgG_Bin[halfHeight][i] == 0) {
//            currentWidth += 1;
//            i++;
//        }
//        else if (imgG_Bin[halfHeight][i+1] == 0) {
//            currentWidth += 2;
//            i += 1;
//        }
//        else if (imgG_Bin[halfHeight][i+2] == 0) {
//            currentWidth += 3;
//            i += 2;
//        }
//        else {
//            if (currentWidth > maxWidth)
//                maxHeight = currentWidth;
//            
//            currentWidth = 0;
//            i++;
//        }
//    }
//    int boxWidth = maxWidth;
//    
//    
//    // Start at centre, head toward top-left
//    int hPos = halfHeight;
//    int wPos = halfWidth;
//    while (1) {
//        if (imgG_Bin[hPos-1][wPos-1] == 0) {
//            hPos = hPos-1;
//            wPos = wPos-1;
//        }
//        else if (imgG_Bin[hPos-1][wPos] == 0) {
//            hPos = hPos-1;
//        }
//        else if (imgG_Bin[hPos][wPos-1] == 0) {
//            wPos = wPos-1;
//        }
//        else if (imgG_Bin[hPos-1][wPos+1] == 0) {
//            hPos = hPos-1;
//            wPos = wPos+1;
//        }
//        else
//            break;
//    }
//    
//    // Create single array
//    
//    // Create inverse array
//    int imgG_Bin_Inverse[IMG_H][IMG_W];
//    for (h = 0; h < IMG_H; h++) {
//        for (w = 0; w < IMG_W; w++) {
//            imgG_Bin_Inverse[h][w] = !imgG_Bin_Inverse[h][w];
//        }
//    }
//    
//    int imgAll[IMG_H][IMG_W];
//    for (h = 0; h < IMG_H; h++) {
//        for (w = 0; w < IMG_W; w++) {
//            imgAll[h][w] = (((2*imgG_Bin_Inverse[h][w]) + 3*(imgG_Bin_Inverse[h][w] & imgB_Bin[h][w])) + (imgG_Bin_Inverse[h][w] & imgR_Bin[h][w]));
//        }
//    }
//    // NOTE: In imgAll, R=3, G=2, B=5, 0=ignore
//    const int cRED = 3, cGREEN = 2, cBLUE = 5;
//    
//    
//    // Vars for main parse
//    int j = hPos;
//    int maxLength = 0;
//    int rowUpTo = 1;
//    int mode = 0;
//    int numBoxes = 0;
//    
//    // Main parse
//    while (1) {
//        // Loop condition
//        j++;
//        if (j > hPos + maxHeight)
//            break;
//        
//        // Switch on colour mode
//        switch (mode) {
//            case RED:
//                if (imgAll[j][halfWidth] == cRED) {
//                    maxLength++;
//                }
//                else if (imgAll[j+1][halfWidth] == cRED) {
//                    maxLength += 2;
//                    i++;
//                }
//                else if (imgAll[j+2][halfWidth] == cRED) {
//                    maxLength += 3;
//                    i += 2;
//                }
//                else {
//                    if (maxLength > MIN_BOX_HEIGHT) {
//                        numBoxes = maxLength / boxHeight;
//                        
//                        if (numBoxes == 2) {
//                            plan[rowUpTo] = RED;
//                            plan[rowUpTo+1] = RED;
//                            rowUpTo += 2;
//                        }
//                        else if (numBoxes == 3) {
//                            plan[rowUpTo] = RED;
//                            plan[rowUpTo+1] = RED;
//                            plan[rowUpTo+2] = RED;
//                            rowUpTo += 3;
//                        }
//                        else {
//                            plan[rowUpTo] = RED;
//                            rowUpTo++;
//                        }
//                    }
//                    
//                    maxLength = 0;
//                    if (imgAll[i][halfWidth] == cGREEN)
//                        mode = GREEN;
//                    else
//                        mode = BLUE;
//                    maxLength++;
//                }
//                break;
//            
//            case GREEN:
//                if (imgAll[j][halfWidth] == cGREEN) {
//                    maxLength++;
//                }
//                else if (imgAll[j+1][halfWidth] == cGREEN) {
//                    maxLength += 2;
//                    i++;
//                }
//                else if (imgAll[j+2][halfWidth] == cGREEN) {
//                    maxLength += 3;
//                    i += 2;
//                }
//                else {
//                    if (maxLength > MIN_BOX_HEIGHT) {
//                        numBoxes = maxLength / boxHeight;
//                        
//                        if (numBoxes == 2) {
//                            plan[rowUpTo] = GREEN;
//                            plan[rowUpTo+1] = GREEN;
//                            rowUpTo += 2;
//                        }
//                        else if (numBoxes == 3) {
//                            plan[rowUpTo] = GREEN;
//                            plan[rowUpTo+1] = GREEN;
//                            plan[rowUpTo+2] = GREEN;
//                            rowUpTo += 3;
//                        }
//                        else {
//                            plan[rowUpTo] = GREEN;
//                            rowUpTo++;
//                        }
//                    }
//                    
//                    maxLength = 0;
//                    if (imgAll[i][halfWidth] == cRED)
//                        mode = RED;
//                    else
//                        mode = BLUE;
//                    maxLength++;
//                }
//                break;
//            
//            case BLUE:
//                if (imgAll[j][halfWidth] == cBLUE) {
//                    maxLength++;
//                }
//                else if (imgAll[j+1][halfWidth] == cBLUE) {
//                    maxLength += 2;
//                    i++;
//                }
//                else if (imgAll[j+2][halfWidth] == cBLUE) {
//                    maxLength += 3;
//                    i += 2;
//                }
//                else {
//                    if (maxLength > MIN_BOX_HEIGHT) {
//                        numBoxes = maxLength / boxHeight;
//                        
//                        if (numBoxes == 2) {
//                            plan[rowUpTo] = BLUE;
//                            plan[rowUpTo+1] = BLUE;
//                            rowUpTo += 2;
//                        }
//                        else if (numBoxes == 3) {
//                            plan[rowUpTo] = BLUE;
//                            plan[rowUpTo+1] = BLUE;
//                            plan[rowUpTo+2] = BLUE;
//                            rowUpTo += 3;
//                        }
//                        else {
//                            plan[rowUpTo] = BLUE;
//                            rowUpTo++;
//                        }
//                    }
//                    
//                    maxLength = 0;
//                    if (imgAll[i][halfWidth] == cRED)
//                        mode = RED;
//                    else
//                        mode = GREEN;
//                    maxLength++;
//                }
//                break;
//                
//            default: // Initial
//                if (imgAll[i][halfWidth] == cRED)
//                    mode = RED;
//                else if (imgAll[i][halfWidth] == cGREEN)
//                    mode = GREEN;
//                else
//                    mode = BLUE;
//                
//                maxLength++;
//                break;
//        }
//    }
    
    
    return *(plan); // TODO: Check if returning the right thing
}

int * readPlanWithCamera() {
//    int * plan = (int *) malloc(sizeof(int) * ROWS);
    
    takePhoto();
    return parsePhoto();
    
//    plan[0] = 1;
//    plan[1] = 2;
//    plan[2] = 3;
//    
//    return plan;
}