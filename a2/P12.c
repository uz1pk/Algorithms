/**
* Name: Usman Zaheer
* Class: CIS 3490
**/
 
#include "A2.h"
 
void P12(int* data) {
    int* tempData = (int*)malloc(sizeof(int) * 50000);
    if(!tempData) {
        fprintf(stderr, "Malloc failed\n");
        exit(-1);
    }

    int count = 0;
    clock_t start = clock();
    
    count = alteredMergeSort(data, tempData, 0, 49999);
    
    clock_t end = clock();

    if(start == -1 || end == -1) {
        fprintf(stderr, "clock failed\n");
        exit(-1);
    }
    double ms = (double)(end - start);
    
    printf("A Divide and Conquer program for Counting Inversions\nCount = %d\nExecution time = %0.1lf ms\n\n", count, ms);
    
    free(tempData);
}
 
int alteredMergeSort(int* data, int* tempData, int left, int right) {
    int count = 0;
    int middle;
 
    if(right > left) {
        middle = (right + left) / 2;
    
        count += alteredMergeSort(data, tempData, left, middle);
        count += alteredMergeSort(data, tempData, middle + 1, right);
    
        count += mergeFunction(data, tempData, left, middle + 1, right);
    }
 
    return count;
}
 
int mergeFunction(int* data, int* tempData, int left, int middle, int right) {
    int count = 0;
    int mergeIndex = left;
    int leftArray = left;
    int rightArray = middle;
    while ((leftArray <= middle - 1) && (rightArray <= right)) {
        if (data[leftArray] <= data[rightArray]) {
            tempData[mergeIndex++] = data[leftArray++];
        }
        else {
            tempData[mergeIndex++] = data[rightArray++];
            count = count + (middle - leftArray);
        }
    }
    
    while (leftArray <= (middle - 1)) {
        tempData[mergeIndex++] = data[leftArray++];
    }
    while (rightArray <= right) {
        tempData[mergeIndex++] = data[rightArray++];
    }
    for (leftArray = left; leftArray <= right; leftArray++) {
        data[leftArray] = tempData[leftArray];
    }
    
    return count;
}
