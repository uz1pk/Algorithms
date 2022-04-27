/**
 * Usman Zaheer
 * CIS 3490
 **/

#include "a4.h"

int getUniqueWords(char *fileName, char *words[])
{
    int counter = 0, unique = 0, status, i;
    char temp[250];
    FILE *p = fopen(fileName, "r");

    // parses all data/unique words from files and also stores number of unique word
    if (!p)
    {
        fprintf(stderr, "File does not exist\n");
        return 0;
    }

    while (!(feof(p)) && counter < MAX_WORDS)
    {
        fscanf(p, "%s", temp);
        status = 0;
        for (i = 0; i < counter; i++)
        {
            if (!(strcmp(temp, words[i])))
            {
                status = 1;
                break;
            }
        }
        if (!status)
        {
            unique++;
        }
        words[counter] = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
        strcpy(words[counter++], temp);
    }

    fclose(p);
    return unique;
}

// initializes structure array (based on length) to empty values
Word *initializeWordMetadata(int unique)
{
    Word *arr = (Word *)malloc(sizeof(Word) * unique);
    for (int i = 0; i < unique; i++)
    {
        arr->occurrences = 0;
        arr->probability = 0.0;
        strcpy(arr->word, "\0");
    }

    return arr;
}

// frees all stored words
void freeWords(char *words[])
{
    for (int i = 0; i < MAX_WORDS; i++)
    {
        free(words[i]);
    }
}

// compare function for qsort();
int compare(const void *w1, const void *w2)
{
    Word *word1 = (Word *)w1;
    Word *word2 = (Word *)w2;

    return strcmp(word1->word, word2->word);
}

// 2d array free function (int)
void freeMatrix(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

// 2d array free function (float)
void freeMatrixFloat(float **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);
}
