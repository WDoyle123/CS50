#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            // Selects Pixel
            RGBTRIPLE pixel = image[i][j];

            // Calaculates the avg colour of the pixel
            int avgColour = round(((float)pixel.rgbtBlue + (float)pixel.rgbtGreen + (float)pixel.rgbtRed) / 3.0);

            // Changes the value of the RGB values
            image[i][j].rgbtBlue = avgColour;
            image[i][j].rgbtRed = avgColour;
            image[i][j].rgbtGreen = avgColour;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get Colours of Pixel
            int originalRed = image[i][j].rgbtRed;
            int originalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;

            // Sepia Algo
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // Checks if sepiaRed is greater than 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            // Checks if sepiaBlue is greater than 255
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Checks if sepiaGreen is greater than 255
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            // Apply Sepia
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Finds the centre point
            int halfWidth = width / 2;

            // Store the temporary value
            RGBTRIPLE tempValue = image[i][j];

            // Gets the value to swap with the temp value
            image[i][j] = image[i][width - (j + 1)];

            // Swaps with temp value
            image[i][width - (j + 1)] = tempValue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    // Check around pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0;
            int totalBlue = 0;
            int totalGreen = 0;
            float counter = 0.00;

            // Get neighbour
            for (int y = -1; y < 2; y++)
            {
                for (int x = -1; x < 2; x++)
                {
                    int currentX = j + x;
                    int currentY = i + y;

                    // Check if in boundary
                    if (currentY < 0 || currentY > (height - 1) || currentX < 0 || currentX > (width - 1))
                    {
                        continue;
                    }

                    // Get image value
                    totalRed += image[currentY][currentX].rgbtRed;
                    totalBlue += image[currentY][currentX].rgbtBlue;
                    totalGreen += image[currentY][currentX].rgbtGreen;

                    counter++;

                }
                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
            }
        }

    }
    for (int i = 0 ; i < height; i++)
    {
        for (int j = 0;  j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;

        }
    }
    return;

}


