/**
 * Usman Zaheer
 * CIS 3490
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH_LIMIT 1000

void p11(int *x, int *y, int max);

void p12(int *x, int *y, int max);
void alteredMergeSort(int *data, int *tempData, int left, int right);
void mergeFunction(int *data, int *tempData, int left, int middle, int right);

void p21(char *string);
void p22(char *string);
void p23(char *string);
int max(int first, int second); // helper function to get max between two numbers
