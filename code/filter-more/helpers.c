#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get colours
            float RED = image[i][j].rgbtRed;
            float GREEN = image[i][j].rgbtGreen;
            float BLUE = image[i][j].rgbtBlue;

            // Find AVG colour
            int colourAvg = round((RED + GREEN + BLUE) / 3);

            // Apply AVG colour to each channel
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = colourAvg;
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
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;

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


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy of original
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    //
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialsie colour and direction values
            int redX = 0;
            int redY = 0;

            int greenX = 0;
            int greenY = 0;

            int blueX = 0;
            int blueY = 0;


            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    int currentX = i - 1 + x;
                    int currentY = j - 1 + y;

                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    // Get the X colour values
                    redX = redX + (image[currentX][currentY].rgbtRed * Gx[x][y]);
                    blueX = blueX + (image[currentX][currentY].rgbtBlue * Gx[x][y]);
                    greenX = greenX + (image[currentX][currentY].rgbtGreen * Gx[x][y]);

                    // Get the Y colour values
                    redY = redY + (image[currentX][currentY].rgbtRed * Gy[x][y]);
                    blueY = blueY + (image[currentX][currentY].rgbtBlue * Gy[x][y]);
                    greenY = greenY + (image[currentX][currentY].rgbtGreen * Gy[x][y]);
                }
            }
            int red = round(sqrt((redX * redX) + (redY * redY)));
            int green = round(sqrt((greenX * greenX) + (greenY * greenY)));
            int blue = round(sqrt((blueX * blueX) + (blueY * blueY)));

            // Cap the max colour to 255
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            temp[i][j].rgbtRed = red;
            temp[i][j].rgbtGreen = green;
            temp[i][j].rgbtBlue = blue;
        }

    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }

    return;
}
