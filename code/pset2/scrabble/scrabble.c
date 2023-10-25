#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int computeWordValue(string word);
int computeWordScore(int wordValue);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = computeWordValue(word1);
    int score2 = computeWordValue(word2);

    // Print the winner

    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }

    if (score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }
    if (score1 == score2)
    {
        printf("Tie!\n");
    }

}

int computeWordValue(string word)
{
    int wordValue = 0, wordLength = strlen(word);


    for (int i = 0; i < wordLength; i++)
    {
        int letter = word[i];

        if (letter > 96 && letter < 123) //Characters between a and z
        {
            wordValue = wordValue + POINTS[letter - 97]; // Corresponds to a being 0 and z as 26
        }
        if (letter > 64 && letter < 91) // Characters between A and Z
        {
            wordValue = wordValue + POINTS[letter - 65]; // Corresponds to A being 0 and Z as 26
        }
    }
    return wordValue;

}

// to improve could us isupper and islower but i think it looks clearer using current approach



