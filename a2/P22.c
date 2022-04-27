/**
 * Name: Usman Zaheer
 * Class: CIS 3490
**/

#include "A2.h"

int quickHullIndex = 0;
set quickHull[50];

void P22(set* setS) {
    set* s1 = (set*)malloc(sizeof(set));
    set* s2 = (set*)malloc(sizeof(set));
    int maxIndex = 0;
    int minIndex = 0;
    int positivePlane = 1;
    int negativePlane = -1;

    printf("A divide and conquer program for finding convex hull\n");
    clock_t start = clock();
    for(int i = 0; i < 30000; i++) {
        if (setS[i].x < setS[minIndex].x) {
            minIndex = i;
        }
        if (setS[i].x > setS[maxIndex].x) {
            maxIndex = i;
        }
    }
    getQuickHull(setS, 30000, setS[minIndex], setS[maxIndex], positivePlane);
    getQuickHull(setS, 30000, setS[minIndex], setS[maxIndex], negativePlane);
    clock_t end = clock();
    quickHullIndex--;

    double ms = (double)(end - start);
    printf("Time for computing hull: %0.1lf ms\n", ms);

    for(int i = 0; i < quickHullIndex; i++) {
        printf("(%0.1f, %.1f)\n", quickHull[i].x, quickHull[i].y);
    }

    free(s1);
    free(s2);
}

void getQuickHull(set* setS, int n, set min, set max, int signOfSide) {
    int isHullLine = -1;
    double currMaxDistance = 0.0;

    for(int i = 0; i < n; i++) {
        double temp = distanceCalc(min, max, setS[i]);
        int tempSide = isNegativePlane(min, max, setS[i]);
        if(tempSide == signOfSide && currMaxDistance < temp) {
            isHullLine = i;
            currMaxDistance = temp;
        }
    }

    int maxExist = -1;
    int minExist = -1;

    if(isHullLine == -1) {
        for(int i = 0; i < quickHullIndex; i++) {
            if((quickHull[i].x == min.x && quickHull[i].y == min.y)) {
                minExist = 1;
            }
            if(quickHull[i].x == max.x && quickHull[i].y == max.y) {
                maxExist = 1;
            }
        }
        if(maxExist == 1 && minExist == 1);
        else if(minExist == 1) {
            quickHull[quickHullIndex++] = max;
        }
        else if(maxExist == 1) {
            quickHull[quickHullIndex++] = min;
        }
        else {
            quickHull[quickHullIndex++] = min;
            quickHull[quickHullIndex++] = max;
        }
        return;
    }
    int minRelative = (isNegativePlane(setS[isHullLine], min, max)) * -1;
    int maxRelative = (isNegativePlane(setS[isHullLine], max, min)) * -1;

    getQuickHull(setS, n, setS[isHullLine], min, minRelative);
    getQuickHull(setS, n, setS[isHullLine], max, maxRelative);
}

double distanceCalc(set pointMin, set pointMax, set currPoint) {
    double pointDistanceA;
    double pointDistanceB;
    double distance;

    pointDistanceA = (currPoint.y - pointMin.y) * (pointMax.x - pointMin.x);
    pointDistanceB = (pointMax.y - pointMin.y) * (currPoint.x - pointMin.x);
    //fabs is needed to represent distance in magnitude 
    distance = fabs(pointDistanceA - pointDistanceB);

    return distance;
}

int isNegativePlane(set pointMin, set pointMax, set currPoint) {
    double pointDistanceA;
    double pointDistanceB;
    float val;
    int signOfSide = 0;

    pointDistanceA = (currPoint.y - pointMin.y) * (pointMax.x - pointMin.x);
    pointDistanceB = (pointMax.y - pointMin.y) * (currPoint.x - pointMin.x);
    val = pointDistanceA - pointDistanceB;

    if(val > 0) {
        signOfSide = 1;
    }

    else if(val < 0) {
        signOfSide = -1;
    }

    return signOfSide;
}
