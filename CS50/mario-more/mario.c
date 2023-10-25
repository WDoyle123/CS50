#include <cs50.h>
#include <stdio.h>

int main(void)
{

// Get input from user that fits with constraints

    int height;
    do
    {
        height = get_int("Height:");
    }
    // Will continue when user has input value between 1 and 8 (including 1 and 8)
    while (height < 1 || height > 8);

// Construst triangle


// Construct rows
    for (int i = 0; i < height; i++)
    {
        // Construct columns, where j = height + i + 2
        for (int j = 0; j < height + i + 3; j++)
        {
            //Construct spaces where, first two args are the middle of pyrimid and final arg is spaces from the left
            if (j == height || j == height + 1 || i + j < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }


}