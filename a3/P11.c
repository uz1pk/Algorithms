/**
 * Usman Zaheer
 * CIS 3490
 **/

#include "A3.h"

void p11(int *x, int *y, int max)
{
    int numIntervals = 0;
    int commonPoint = 0;
    int currMin = x[0];
    int currMax = y[0];

    clock_t start = clock();

    // this loop finds the smallest and largest interval in the set
    for (int i = 0; i < max; i++)
    {
        if (x[i] < currMin)
        {
            currMin = x[i];
        }
        if (y[i] > currMax)
        {
            currMax = y[i];
        }
    }

    /*
    Using the smallest and largest interval
    Check all the intervals inbetween to see if they
    are contained
    */
    for (int i = currMin + 1; i < currMax; i++)
    {
        int tempCount = 0;
        for (int j = 0; j < max; j++)
        {
            if (x[j] < i && y[j] > i)
            {
                tempCount++;
            }
        }
        if (tempCount > numIntervals)
        {
            numIntervals = tempCount;
            commonPoint = i;
        }
    }

    clock_t end = clock();

    if (start == -1 || end == -1)
    {
        fprintf(stderr, "clock failed\n");
        exit(-1);
    }
    double ms = (double)(end - start) / 1000;

    printf("A Brute force program for finding max number of intervals\nThe maximum number of intervals: %d\nThe intervals include point: %d\nTime for finding maximum number: %0.0lf ms\n", numIntervals, commonPoint, ms);
    printf("\n");
}
