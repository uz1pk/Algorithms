/**
 * Name: Usman Zaheer
 * Class: CIS 3490
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} set;

typedef struct {
    set p1;
    set p2;
} lineSegment;

void getIntegerData(int* data, char* filename);
void getCoordinateData(set* setS, char* filename);

void P11(int* data);
void P12(int* data);
int alteredMergeSort(int* data, int* tempData, int left, int right);
int mergeFunction(int* data, int* tempData, int left, int middle, int right);

void P21(set* setS);
void getBruteForceConvexHull(set* setS);

void P22(set* setS);
void getQuickHull(set* setS, int n, set min, set max, int signOfSide);
double distanceCalc(set pointMin, set pointMax, set currPoint);
int isNegativePlane(set pointMin, set pointMax, set currPoint);

void bruteForceShortestDistance(set* s1, set* s2);
float getLeftPath(set* s1, set* s2);
float getRightPath(set* s1, set* s2);
void printPath(set* s1, set* s2, int direction);