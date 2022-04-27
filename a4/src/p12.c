/**
 * Usman Zaheer
 * CIS 3490
 **/

#include "a4.h"

void p12()
{
    Word *wordMeta;
    char buffer[250];
    char *userKey;
    char *words[MAX_WORDS];
    int status, numUnique, counter, i, j;

    // read in all unique words from file and store number of unique words
    numUnique = getUniqueWords("data_A4_Q1.txt", words);
    if (!numUnique)
    {
        return;
    }

    wordMeta = initializeWordMetadata(numUnique);

    // extract data from unique words and store them in the word meta data array
    counter = 0;
    for (i = 0; i < MAX_WORDS; i++)
    {
        status = 0;
        for (j = 0; j < counter; j++)
        {
            if (!(strcmp(words[i], wordMeta[j].word)))
            {
                status = 1;
                wordMeta[j].occurrences++;
                break;
            }
        }
        if (!status)
        {
            wordMeta[counter].occurrences++;
            strcpy(wordMeta[counter++].word, words[i]);
        }
    }
    freeWords(words);

    // calculate probabilities after all occurrances are counted
    for (i = 0; i < numUnique; i++)
    {
        wordMeta[i].probability = (float)(wordMeta[i].occurrences) / (float)MAX_WORDS;
    }

    // sort words alphabetically
    qsort(wordMeta, numUnique, sizeof(Word), compare);

    // prompt for key
    printf("Enter a key:\n");
    fflush(stdin);
    scanf("%s", buffer);
    userKey = (char *)malloc(sizeof(char) * ((int)strlen(buffer) + 1));
    strcpy(userKey, buffer);

    // apply algorithm
    greedyTechnique(wordMeta, userKey, 0, numUnique);

    free(wordMeta);
    free(userKey);
}

void greedyTechnique(Word *words, char *key, int start, int end)
{
    // if we are on the border/diagonal (aka the word was not found) of the main table
    if (start >= end)
    {
        printf("Not found.\n");
        return;
    }

    float currMax = 0.0;  // this variable is used to represent the current maximum of tree/sub-tree
    int newIndex = start; // variable to store new index of start/end
    int result = 0;

    // apply greedy algorithm by finding the current maximum element in tree
    for (int i = start; i < end + 1; i++)
    {
        if (words[i].probability >= currMax)
        {
            newIndex = i;
            currMax = words[i].probability;
        }
    }
    result = strcmp(key, words[newIndex].word); // compare current maximum element of tree with key

    // recursively set sub tree based on if key is greater than or less than root
    // if it is equal than root is found
    if (result == 0)
    {
        printf("Compared with %s (%0.3f), found.\n", words[newIndex].word, words[newIndex].probability);
    }
    else if (result > 0)
    {
        printf("Compared with %s (%0.3f), go right subtree.\n", words[newIndex].word, words[newIndex].probability);
        greedyTechnique(words, key, newIndex + 1, end);
    }
    else if (result < 0)
    {
        printf("Compared with %s (%0.3f), go left subtree.\n", words[newIndex].word, words[newIndex].probability);
        greedyTechnique(words, key, start, newIndex - 1);
    }
}

// driver Function
int main()
{
    p12();

    return 0;
}
