/**
 * Usman Zaheer
 * CIS 3490
 **/

#include "A3.h"

void p22(char *string)
{
    char buffer[LENGTH_LIMIT];
    int shiftTable[LENGTH_LIMIT];
    int textLen = strlen(string);
    int count = 0;
    int numShifts = 0;

    // prompt user for input
    printf("A Horpools Algorithm program for string search.\nEnter search pattern for Q2 data\n");
    if (!fgets(buffer, LENGTH_LIMIT, stdin))
    {
        fprintf(stderr, "Pattern entered is too long\n");
        exit(-1);
    }
    int searchLen = strlen(buffer) - 1;
    int searchIndex = searchLen - 1;

    clock_t start = clock();

    // populating shift Table
    for (int i = 0; i < LENGTH_LIMIT; i++)
    {
        shiftTable[i] = searchLen;
    }

    for (int i = 0; i < searchIndex; i++)
    {
        int asciiIndex = buffer[i];
        shiftTable[asciiIndex] = searchIndex - i;
    }

    // Apply brute force algorithm. But determine shift amount
    // using the created shift table above.
    int shift = searchIndex;
    while (shift < textLen)
    {
        int patternIndex = 0;
        while (patternIndex <= searchIndex && buffer[searchIndex - patternIndex] == string[shift - patternIndex])
        {
            patternIndex++;
        }
        int shiftIndex = string[shift];
        if (patternIndex == searchLen)
        {
            count++;
            int max = shift + searchLen;
            if (max > textLen)
            {
                shift += 1;
            }
            else
            {
                shift += searchLen;
            }
        }
        else
        {
            shift += shiftTable[shiftIndex];
        }
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
