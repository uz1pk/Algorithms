/**
 * Usman Zaheer
 * CIS 3490
 **/

#include "A3.h"

void p21(char *string)
{
    char buffer[LENGTH_LIMIT];
    int textLen = strlen(string);
    int count = 0;
    int numShifts = 0;
    int i, j;

    // prompt user for input
    printf("A Brute force program for string search.\nEnter search pattern for Q2 data\n");
    if (!fgets(buffer, LENGTH_LIMIT, stdin))
    {
        fprintf(stderr, "Pattern entered is too long\n");
        exit(-1);
    }
    int searchLen = strlen(buffer) - 1;

    clock_t start = clock();

    /*
    Shift through each and every character of the text.
    All the while comparing character by character to see
    if there is a match.
    */
    for (i = 0; i < (textLen - searchLen + 1); i++)
    {
        int tempCounter = 0;
        for (j = 0; j < searchLen; j++)
        {
            if (string[i + j] != buffer[j])
            {
                break;
            }
            else
            {
                tempCounter++;
            }
        }
        if (searchLen == tempCounter)
        {
            count++;
        }
        else
        {
            numShifts++;
        }
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
