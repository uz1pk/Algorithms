/**
 * Usman Zaheer
 * CIS 3490
 **/

#include "A3.h"

void p23(char *string)
{
    char buffer[LENGTH_LIMIT];
    int badSymbolTable[LENGTH_LIMIT];
    int textLen = strlen(string);
    int count = 0;
    int numShifts = 0;

    // prompt user for input
    printf("A Boyer Moore Algorithm program for string search.\nEnter search pattern for Q2 data\n");
    if (!fgets(buffer, LENGTH_LIMIT, stdin))
    {
        fprintf(stderr, "Pattern entered is too long\n");
        exit(-1);
    }
    int searchLen = strlen(buffer) - 1;
    int goodSymbolTable[searchLen];
    int searchIndex = searchLen - 1;

    clock_t start = clock();

    // Initializing tables
    for (int i = 0; i < LENGTH_LIMIT; i++)
    {
        badSymbolTable[i] = searchLen;
    }
    for (int i = 0; i < searchLen; i++)
    {
        int asciiIndex = buffer[i];
        badSymbolTable[asciiIndex] = searchIndex - i;
        goodSymbolTable[i] = 0;
    }

    // Populating good suffix table by accounting for all cases
    int latestPrefix = 1, l, z;
    for (l = searchIndex; l > -1; l--)
    {
        int status = 1, temp;
        int suffixK = searchLen - (l + 1);

        for (temp = 0; temp < suffixK; temp++)
        {
            status = (buffer[temp] != buffer[(l + 1) + temp]) ? 0 : 1;
        }
        if (status == 1)
        {
            latestPrefix = l + 1;
        }
        goodSymbolTable[l] = (searchIndex - l) + latestPrefix;
    }

    for (z = 0; z < searchIndex; z++)
    {
        int temp;
        char indexFirst = '\0';
        char indexSecond = '\0';
        for (temp = 0; (indexFirst == indexSecond) && (temp < z); temp++)
        {
            indexFirst = buffer[z - temp];
            indexSecond = buffer[searchIndex - temp];
        }
        goodSymbolTable[searchIndex - temp] = (indexFirst != indexSecond) ? (searchIndex - z + temp) : 0;
    }

    /*
    Apply the brute force algorithm however isntead of incrementing by one
    you increment by which ever one allows a larger increase, whether it be
    the bad character or good suffix table. We also have to make sure
    potential misses are accounted for by the good suffix table.
    */
    int shift = searchIndex;
    while (shift < textLen)
    {
        int patternIndex = searchIndex;
        int tempShift = shift;
        while (patternIndex >= 0 && buffer[patternIndex] == string[tempShift])
        {
            patternIndex--;
            tempShift--;
        }
        if (tempShift < 0)
        {
            tempShift = 0;
        }
        int currIndex = string[tempShift];
        int holderShift = max(badSymbolTable[currIndex], 1);
        int goodShift = (patternIndex < 0) ? goodSymbolTable[0] : goodSymbolTable[patternIndex];

        if (patternIndex < 0)
        {
            count++;
            tempShift += goodShift;
        }
        else
        {
            tempShift += max(holderShift, goodShift);
        }
        shift = tempShift;
        numShifts++;
    }

    clock_t end = clock();
    if (start == -1 || end == -1)
    {
        fprintf(stderr, "clock failed\n");
        exit(-1);
    }
    double ms = (double)(end - start) / 1000;

    printf("Count: %d\nShifts: %d\nExecution time = %0.0lf ms\n", count, numShifts, ms);
    printf("\n");
}

int max(int first, int second)
{
    return (first > second) ? first : second;
}
