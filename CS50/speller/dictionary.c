// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <cs50.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
unsigned int counter;
unsigned int hashValue;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // hashValue = hash(word);
    node *cursor = table[hash(word)];
    while (cursor != 0)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long total = 0;

    int wordLength = strlen(word);

    if (wordLength == 1)
    {
        hashValue = (677 * (tolower(word[0]) - 97));
        // Eg: A = 0; B = 676

        return total;
    }

    // If 2 Letter word
    if (wordLength == 2)
    {
        hashValue = ((677 * (tolower(word[0]) - 97)) + (27 * (tolower(word[1]) - 97)));
        return total;
    }

    // If 3 Letter word
    if (wordLength > 2)
    {
        hashValue = ((677 * (tolower(word[0]) - 97)) + (27 * (tolower(word[1]) - 97)) + (tolower(word[2]) - 97));
        return total;
    }

    return total;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // fopen dictionary
    FILE *fp = fopen(dictionary, "r");
    //check if NULL value
    if (fp == NULL)
    {
        printf("Could not open file...");
        return 1;
    }
    char word[LENGTH + 1];

    // Read strings until EOF
    while (fscanf(fp, "%s", word) != EOF)
    {
        // Allocate memeory for node
        node *n = malloc(sizeof(node));

        // Check if malloc return a NULL value
        if (n == NULL)
        {
            printf("malloc returned a NULL value");
            return false;
        }

        // Copy a word into node
        strcpy(n->word, word);
        n->next = NULL;
        hashValue = hash(word);
        if (table[hashValue] == NULL)
        {
            table[hashValue] = n;
        }
        else
        {
            n->next = table[hashValue];
            table[hashValue] = n;
        }

        // Count words in dictionary
        counter++;
    }
    fclose(fp);
    return true;
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (counter > 0)
    {
        return counter;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
