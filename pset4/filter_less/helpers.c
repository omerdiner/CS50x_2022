#include "helpers.h"
#include <math.h>
 // Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            int avg = round((green + red + blue) / 3);

            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            if (sepiaRed > 255) {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255) {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255) {
                sepiaBlue = 255;
            }

            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
    RGBTRIPLE tmp[height][width];
    int i, j , x, y, currentX, currentY;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            tmp[i][j] = image[i][j];

        }
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
        	
            int totalRed = 0, totalGreen = 0, totalBlue = 0;
            int validCount = 0;

            for (x = -1; x < 2; x++) {
                for (y = -1; y < 2; y++) {
                    currentX = x + i;
                    currentY = y + j;

                    if (currentX > (height - 1) || currentX < 0 || currentY > (width - 1) || currentY < 0) {
                        continue;
                    }

                    validCount++;

                    totalRed += image[currentX][currentY].rgbtRed;
                    totalBlue += image[currentX][currentY].rgbtBlue;
                    totalGreen += image[currentX][currentY].rgbtGreen;

                }
            }
            
                tmp[i][j].rgbtRed = round((float) totalRed / validCount);
                tmp[i][j].rgbtBlue = round((float) totalBlue / validCount);
                tmp[i][j].rgbtGreen = round((float) totalGreen / validCount);
        }
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
        }
    }

    return;
}
