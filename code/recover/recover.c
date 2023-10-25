#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <stdint.h>
#define FAT 512


typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    FILE *inputFile = fopen(argv[1], "r");

    // Check for correct amount of args
    if (argc != 2)
    {
        printf("Requires one argument...");
        return 1;
    }
    // Check that file is valid
    if (inputFile == NULL)
    {
        printf("Could not open file...");
        return 2;
    }

    // Store Blocks of size FAT
    BYTE buffer[FAT];

    // Track number of images
    int counter = 0;

    // Pointer for recovered images
    FILE *outputFile = NULL;

    // Char filename[8]
    char *fileName = malloc(8 * sizeof(char));

    // Find JPEG header
    while (fread(buffer, sizeof(char), FAT, inputFile))
    {
        // Checks for JPG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter > 0)
            {
                fclose(outputFile);
            }
            // Write JPG name
            sprintf(fileName, "%03i.jpg", counter);

            // Opens file of JPG name
            outputFile = fopen(fileName, "w");

            // Stores amount of images
            counter++;
        }
        // Write JPEG to file if pointer doesnt return a NULL value
        if (outputFile != NULL)
        {
            // Writes image to file
            fwrite(buffer, sizeof(char), FAT, outputFile);
        }


    }

    // Free memeory and closes files
    free(fileName);
    fclose(outputFile);
    fclose(inputFile);
    return 0;
}





