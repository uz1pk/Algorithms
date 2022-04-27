/**
 * Usman Zaheer
 * CIS 3490
 **/

#include "A3.h"

void p12(int *x, int *y, int max)
{
    int numIntervals = 0;
    int commonPoint = 0;

    int *tempData1 = (int *)malloc(sizeof(int) * max);
    int *tempData2 = (int *)malloc(sizeof(int) * max);

    clock_t start = clock();

    // sort the intervals first.
    alteredMergeSort(x, tempData1, 0, max - 1);
    alteredMergeSort(y, tempData2, 0, max - 1);

    /*
    Same search as before however time complexity is cut
    much shorter due to the presort done prior to the function call.
    */
    int i = 1, j = 0, tempCount = 0;
    while (i < max && j < max)
    {
        if (x[i] < y[j])
        {
            tempCount++;
            if (tempCount > numIntervals)
            {
                numIntervals = tempCount;
                commonPoint = x[i] + 1; // open intervals
            }
            i++;
        }
        else if (x[i] == y[j])
        {
            j++;
            i++;
        }
        else
        {
            tempCount--;
            j++;
        }
    }

    clock_t end = clock();

    if (start == -1 || end == -1)
    {
        fprintf(stderr, "clock failed\n");
        exit(-1);
    }
    double ms = (double)(end - start) / 1000;

    printf("A pre-sorting program for finding max number of intervals\nThe maximum number of intervals: %d\nThe intervals include point: %d\nTime for finding maximum number: %0.0lf ms\n", numIntervals, commonPoint, ms);
    printf("\n");

    free(tempData1);
    free(tempData2);
}

void alteredMergeSort(int *data, int *tempData, int left, int right)
{
    int middle;

    if (right > left)
    {
        middle = (right + left) / 2;

        alteredMergeSort(data, tempData, left, middle);
        alteredMergeSort(data, tempData, middle + 1, right);

        mergeFunction(data, tempData, left, middle + 1, right);
    }
}

void mergeFunction(int *data, int *tempData, int left, int middle, int right)
{
    int mergeIndex = left;
    int leftArray = left;
    int rightArray = middle;
    while ((leftArray <= middle - 1) && (rightArray <= right))
    {
        if (data[leftArray] <= data[rightArray])
        {
            tempData[mergeIndex++] = data[leftArray++];
        }
        else
        {
            tempData[mergeIndex++] = data[rightArray++];
        }
    }

    while (leftArray <= (middle - 1))
    {
        tempData[mergeIndex++] = data[leftArray++];
    }
    while (rightArray <= right)
    {
        tempData[mergeIndex++] = data[rightArray++];
    }
    for (leftArray = left; leftArray <= right; leftArray++)
    {
        data[leftArray] = tempData[leftArray];
    }
}
