/**
 * Name: Usman Zaheer
 * Class: CIS 3490
**/

#include "A2.h"

void P11(int* data) {
    int count = 0;
    clock_t start = clock();
    for(int i = 0; i < 50000; i++) {
        for(int j = 0; j < 50000; j++) {
            if(data[i] > data[j] && i <  j) {
                count++;
            }
        }
    }
    clock_t end = clock();
    if(start == -1 || end == -1) {
       fprintf(stderr, "clock failed\n");
       exit(-1);
    }
    double ms = (double)(end - start);

    printf("A Brute Force program for Counting Inversions\nCount = %d\nExecution time = %0.1lf ms\n\n", count, ms);
    printf("\n");
}
