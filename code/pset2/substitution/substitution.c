#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Store key value
    string key = argv[1];

    // Must contain 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Must contain 26 characters
    int keyLength = strlen(key);
    if (keyLength != 26)
    {
        printf("Usage: ./substitution key");
        return 1;
    }

    // Checks for duplicate character in key
    for (int i = 0; i < keyLength; i++)
    {
        for (int j = i + 1; j < keyLength; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Duplicate character in key");
                return 1;
            }
        }cd
    }cd
cd
    // Checks for invalid characters in keycd
    for (int i = 0; i < keyLength; i++)cd
    {cd
        if (!isalpha(key[i]))
        {
            printf("Invalid character in key");
            return 1;
        }
    }

    // Read plaintext and sort into alpha order
    string plainText = get_string("plaintext:");
    int textLength = strlen(plainText);
    printf("ciphertext: ");
    for (int i = 0; i < textLength; i++)
    {
        if (isupper(plainText[i]))
        {
            int sortLetter = plainText[i] - 'A';
            int cipherLetter = key[sortLetter];
            cipherLetter = toupper(cipherLetter); //converts back to case of original character
            printf("%c", cipherLetter);
        }
        else if (islower(plainText[i]))
        {
            int sortLetter = plainText[i] - 'a';
            int cipherLetter = key[sortLetter];
            cipherLetter = tolower(cipherLetter); //converts back to case of original character
            printf("%c", cipherLetter);
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
}