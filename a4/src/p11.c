/**
 * Usman Zaheer
 * CIS 3490
 **/

#include "a4.h"

void p11()
{
    Word *wordMeta;
    char buffer[250];
    char *userKey;
    char *words[MAX_WORDS];
    float **mainTable;
    int **rootTable;
    int status, numUnique, uniqueIndex2, counter, uniqueIndex, i, j, k, l;

    // read in all unique words from file and store number of unique words
    numUnique = getUniqueWords("data_A4_Q1.txt", words);
    if (!numUnique)
    {
        return;
    }

    uniqueIndex = numUnique + 1;
    uniqueIndex2 = uniqueIndex + 1;
    wordMeta = initializeWordMetadata(numUnique);
    mainTable = (float **)malloc(sizeof(float *) * uniqueIndex2); // [row][column] (rows start at 1, cols start at 0)
    rootTable = (int **)malloc(sizeof(int *) * uniqueIndex2);     // the values will represents the index of the root within the Words in wordMeta array
    for (i = 0; i < uniqueIndex2; i++)
    {
        mainTable[i] = (float *)malloc(sizeof(float) * uniqueIndex);
        rootTable[i] = (int *)malloc(sizeof(int) * uniqueIndex);
    }

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

    freeWords(words); // no longer need words

    // calculate probabilities after all occurrances are counted
    for (i = 0; i < numUnique; i++)
    {
        wordMeta[i].probability = (float)(wordMeta[i].occurrences) / (float)MAX_WORDS;
    }

    // sort words alphabetically
    qsort(wordMeta, numUnique, sizeof(Word), compare);

    // initialize the main and root tables
    for (i = 1; i < uniqueIndex; i++)
    {
        mainTable[i][i - 1] = 0.0;
        mainTable[i][i] = wordMeta[i - 1].probability;
        rootTable[i][i] = i;
    }
    mainTable[uniqueIndex][numUnique] = 0.0;

    // dynamically find the values of each index of the table past diagonal
    for (i = 1; i < numUnique; i++)
    {
        for (j = 1; j <= numUnique - i; j++)
        {
            int index = i + j;
            float sum = 0;
            int minIndex = -1;
            float lowestVal = 9999999.9;

            for (k = j; k < index; k++)
            {
                float tempFloat = mainTable[j][k - 1] + mainTable[k + 1][index];
                if (tempFloat < lowestVal)
                {
                    lowestVal = tempFloat;
                    minIndex = k;
                }
            }
            for (l = j - 1; l < index; l++)
            {
                sum += wordMeta[l].probability;
            }

            mainTable[j][index] = lowestVal + sum;
            rootTable[j][index] = minIndex;
        }
    }

    // prompt for key
    printf("Enter a key:\n");
    scanf("%s", buffer);
    userKey = (char *)malloc(sizeof(char) * ((int)strlen(buffer) + 1));
    strcpy(userKey, buffer);

    printf("%d\n", strcmp(userKey, "of"));

    // apply algorithm
    dynamicSearch(wordMeta, userKey, mainTable, rootTable, 1, numUnique);

    freeMatrixFloat(mainTable, uniqueIndex2);
    freeMatrix(rootTable, uniqueIndex2);
    free(wordMeta);
    free(userKey);
}

void dynamicSearch(Word *words, char *key, float **probs, int **roots, int row, int col)
{
    // if we are on the border/diagonal (aka the word was not found) of the main table
    if (row > col)
    {
        printf("Not found.\n");
        return;
    }

    int currRoot = roots[row][col];
    int index = currRoot - 1;                    // this is to get the actual index within words of the current root
    int result = strcmp(key, words[index].word); // compare the key to the current word of root

    // recursively search tree based on if key is greater than or less than root
    // if it is equal than root is found
    if (result == 0)
    {
        printf("Compared with %s (%0.3f), found.\n", words[index].word, probs[row][col]);
    }
    else if (result > 0)
    {
        printf("Compared with %s (%0.3f), go right subtree.\n", words[index].word, probs[row][col]);
        dynamicSearch(words, key, probs, roots, currRoot + 1, col);
    }
    else if (result < 0)
    {
        printf("Compared with %s (%0.3f), go left subtree.\n", words[index].word, probs[row][col]);
        dynamicSearch(words, key, probs, roots, row, index);
    }
}

// driver Function
int main()
{
    p11();

    return 0;
}
