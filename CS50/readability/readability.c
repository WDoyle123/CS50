#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


int main(void)
{
    int countLetters(string text);
    int countWords(string text);
    int countSentences(string text);
    int index(int numLet, int numWor, int numSen);

    string text = get_string("Text: ");

    int testLetters = countLetters(text);
    int testWords = countWords(text);
    int testSentences = countSentences(text);
    int testIndex = index(testLetters, testWords, testSentences);

    //printf("%i Letters\n", testLetters);
    //printf("%i Words\n", testWords);
    //printf("%i Sentences\n", testSentences);


    if (testIndex > 16)
    {
        printf("Grade 16+\n");
    }
    if (testIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    if (testIndex > 1 && testIndex < 17)
    {
        printf("Grade %i\n", testIndex);
    }

}

int countLetters(string text)
{
    // What is a letter?
    // a-z & A-Z
    // What is not a letter?
    // Punctuation & Numbers

    int count = 0, textLength = strlen(text); //find length of the text
    for (int i = 0; i < textLength; i++)
    {
        if (isupper(text[i])) // Index the text and find if it is upper case
        {
            count++; // used to total the number of letters
        }
        if (islower(text[i])) // Index the text and find if it is lower case
        {
            count++;
        }
    }

    return count;
}

int countWords(string text)
{
    //What is a word?
    // letters that are seperated by a space , . ! ?

    int count = 0, textLength = strlen(text);
    for (int i = 0; i < textLength; i++)
    {
        if (text[i] == 32 || text[i] == 33 || text[i] == 44 || text[i] == 63
            || text[i] == 46) // If seperated by the above criteria then count++
        {
            count++;
            if (text[i + 1] == 32 || text[i + 1] == 33 || text[i + 1] == 44 || text[i + 1] == 63
                || text[i + 1] == 46) // If followed by another punctuation then remove a count. eg "WOW! Thats cool."
            {
                count--;
            }
        }
    }
    return count;
}

int countSentences(string text)
{
    int count = 0, textLength = strlen(text);
    for (int i = 0; i < textLength; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            count++;
        }
    }
    return count;
}

int index(int numLet, int numWor, int numSen)
{
    float L = (float) numLet / numWor * 100;
    float S = (float) numSen / numWor * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8); // Coleman-Liau index of text

    return index;
}