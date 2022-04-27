/**
 * Name: Usman Zaheer
 * Class: CIS 3490
**/

#include "A2.h"

void getIntegerData(int* data, char* filename) {
    char fileLine[500];
    char* token;
    int index = 0;
    FILE* dataFile = fopen(filename, "r");
    if(!dataFile) {
        fprintf(stderr, "Error opening file\n");
        exit(-1);
    }

    while(fgets(fileLine, 500, dataFile)) {
        token = strtok(fileLine, " \n");
        while(token != NULL) {
            data[index] = atoi(token);
            index++;
            token = strtok(NULL, " \n");
        }
    }

    fclose(dataFile);
}

void getCoordinateData(set* setS, char* filename) {
    char fileLine[500];
    char* token;
    int index = 0;
    FILE* dataFile = fopen(filename, "r");
    if(!dataFile) {
        fprintf(stderr, "Error opening file\n");
        exit(-1);
    }

    while(fgets(fileLine, 500, dataFile)) {
        token = strtok(fileLine, " \n");
        setS[index].x = atof(token);
        token = strtok(NULL, " \n");
        setS[index].y = atof(token);
        index++;
    }
    fclose(dataFile);
}

int main() {
    int* integerData = (int*)malloc(sizeof(int) * 50000);
    set* setS = (set*)malloc(sizeof(set) * 30000);

    if(!integerData || !setS) {
        fprintf(stderr, "Malloc failed\n");
        exit(-1);
    }

    getIntegerData(integerData, "data/data_A2_Q1.txt");
    getCoordinateData(setS, "data/data_A2_Q2.txt");

    P11(integerData);
    P12(integerData);
    P21(setS);
    P22(setS);

    free(integerData);
    free(setS);
    return 0;
}