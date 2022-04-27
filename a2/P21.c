/**
 * Name: Usman Zaheer
 * Class: CIS 3490
**/

#include "A2.h"

int numRightPoints;
int numLeftPoints;
int bruteForceHullIndex = 0;
lineSegment bruteForceHull[50];

void P21(set* setS) {
    set* s1 = (set*)malloc(sizeof(set));
    set* s2 = (set*)malloc(sizeof(set));

    printf("A brute force program for finding the shortest path around\n");
    clock_t start = clock();
    getBruteForceConvexHull(setS);
    clock_t end = clock();

    double ms = (double)(end - start);
    printf("Time for computing hull: %0.1lf ms\n", ms);
    bruteForceHullIndex--;

    printf("Enter the x and y coordinates of s1: ");
    scanf("%f %f", &s1->x, &s1->y);
    printf("Enter the x and y coordinates of s2: ");
    scanf("%f %f", &s2->x, &s2->y);

    bruteForceShortestDistance(s1, s2);
    printf("\n");

    free(s1);
    free(s2);
}

void getBruteForceConvexHull(set* setS) {
    //i == point1 && j == point2
    for(int i = 0; i < 30000; i++) {
        for(int j = 0; j < 30000; j++) {
            if(i == j);
            else {
                float a = setS[j].y - setS[i].y;
                float b = setS[i].x - setS[j].x;
                float c = (setS[i].x * setS[j].y) - (setS[j].x * setS[i].y);
                int positives = 0;
                int negatives = 0;
                int isExtreme = 1;
                
                for(int k = 0; k < 30000; k++) {
                    if(k == i || k == j);
                    else if(((a * setS[k].x) + (b * setS[k].y) - c) > 0) {
                        positives++;
                    }
                    else if(((a * setS[k].x) + (b * setS[k].y) - c) < 0) {
                        negatives++;
                    }
                    else if(((a * setS[k].x) + (b * setS[k].y) - c) == 0) {
                        positives++;
                        negatives++;
                    }
                    if((positives > 0 && negatives > 0) && isExtreme != 1) {
                        isExtreme = -1;
                        break;
                    }
                    else {
                        isExtreme = 2;
                    }
                }   
                if(isExtreme == 2 && positives > 0) {
                    bruteForceHull[bruteForceHullIndex].p1 = setS[i];
                    bruteForceHull[bruteForceHullIndex].p2 = setS[j];
                    bruteForceHullIndex++;
                    break;
                }
                else if(isExtreme == 2 && positives > 0) {
                    bruteForceHull[bruteForceHullIndex].p1 = setS[j];
                    bruteForceHull[bruteForceHullIndex].p2 = setS[i];
                    bruteForceHullIndex++;
                    break;
                }
            }
        }
    }
}

void bruteForceShortestDistance(set* s1, set* s2) {
    float distanceLeft = 0;
    float distanceRight = 0;
    // 0 == right and 1 == left
    int direction = 0;

    numLeftPoints = 1;
    numRightPoints = 1;
    distanceLeft = getLeftPath(s1, s2);
    distanceRight = getRightPath(s1, s2);

    if(distanceLeft < distanceRight) {
        direction = 1;
        printf("The number of points on the shortest path: %d\n", numLeftPoints);
        printf("The distance: %0.1f\n", distanceLeft);
    }
    else {
        printf("The number of points on the shortest path: %d\n", numRightPoints);
        printf("The distance: %0.1f\n", distanceRight);
    }

    printf("The points on the path:\n");
    printPath(s1, s2, direction);
}

//set of a HULL segments, s1 curr point, s2 ending point
float getLeftPath(set* s1, set* s2) {
    int index = 0;
    float currDistance = 0;

    while(bruteForceHull[index].p2.x != s1->x && bruteForceHull[index].p2.y != s1->y) {
        index++;
    }
    float x1 = bruteForceHull[index].p2.x;
    float x2 = bruteForceHull[index].p1.x;
    float y1 = bruteForceHull[index].p2.y;
    float y2 = bruteForceHull[index].p1.y;
    currDistance = (float)sqrt(((pow((x1 - x2), 2)) + (pow((y1 - y2), 2))));
    numLeftPoints++;
    if(bruteForceHull[index].p1.x != s2->x && bruteForceHull[index].p1.y != s2->y) {
        return getLeftPath(&bruteForceHull[index].p1, s2) + currDistance;
    }
    else {
        return currDistance;
    }
    return 0;
}

//set of a HULL segments, s1 curr point, s2 ending point
float getRightPath(set* s1, set* s2) {
    int index = 0;
    float currDistance = 0;

    while(bruteForceHull[index].p1.x != s1->x && bruteForceHull[index].p1.y != s1->y) {
        index++;
    }
    float x1 = bruteForceHull[index].p1.x;
    float x2 = bruteForceHull[index].p2.x;
    float y1 = bruteForceHull[index].p1.y;
    float y2 = bruteForceHull[index].p2.y;
    currDistance = (float)sqrt(((pow((x1 - x2), 2)) + (pow((y1 - y2), 2))));
    numRightPoints++;
    if(bruteForceHull[index].p2.x != s1->x && bruteForceHull[index].p2.y != s2->y) {
        return getRightPath(&bruteForceHull[index].p2, s2) + currDistance;
    }
    else {
        return currDistance;
    }
    return 0;
}

void printPath(set* s1, set* s2, int direction) {
    int index = 0;
    if(direction == 0) {
        while(bruteForceHull[index].p1.x != s1->x && bruteForceHull[index].p1.y != s1->y) {
            index++;
        }
        if(bruteForceHull[index].p2.x != s1->x && bruteForceHull[index].p2.y != s2->y) {
            printf("( %0.1f, %0.1f )\n", s1->x, s1->y);
            printPath(&bruteForceHull[index].p2, s2, direction);
        }
        else {
            printf("( %0.1f, %0.1f )\n", s1->x, s1->y);
            printf("( %0.1f, %0.1f )\n", s2->x, s2->y);
        }
    }
    else {
        while(bruteForceHull[index].p2.x != s1->x && bruteForceHull[index].p2.y != s1->y) {
            index++;
        }
        if(bruteForceHull[index].p1.x != s2->x && bruteForceHull[index].p1.y != s2->y) {
            printf("( %0.1f, %0.1f )\n", s1->x, s1->y);
            printPath(&bruteForceHull[index].p1, s2, direction);
        }
        else {
            printf("( %0.1f, %0.1f )\n", s1->x, s1->y);
            printf("( %0.1f, %0.1f )\n", s2->x, s2->y);
        }
    }
}
