/**
 * Usman Zaheer
 * CIS 3490
 **/

#include "A3.h"

// Driver Function, gets file names, opens them and extracts data to be used.
int main()
{
    // Allocating all data to be used
    char buffer[LENGTH_LIMIT];
    char *string = (char *)malloc(sizeof(char));
    int *x = (int *)malloc(sizeof(int));
    int *y = (int *)malloc(sizeof(int));
    int totalLen = 1;

    // prompting for Q1 file from user
    printf("Enter filename for Q1 data\n");
    fgets(buffer, LENGTH_LIMIT, stdin);
    int len = strlen(buffer);
    buffer[len - 1] = '\0';

    // Extracting all data from user given file
    FILE *dataFile = fopen(buffer, "r");
    int index = 0;
    if (!dataFile)
    {
        fprintf(stderr, "Error opening file 1\n");
        free(x);
        free(y);
        free(string);
        exit(-1);
    }
    while (fgets(buffer, LENGTH_LIMIT, dataFile))
    {
        char *token;
        token = strtok(buffer, " \n");
        x[index] = atoi(token);
        token = strtok(NULL, " \n");
        y[index] = atoi(token);
        index++;
        x = (int *)realloc(x, sizeof(int) * (index + 1));
        y = (int *)realloc(y, sizeof(int) * (index + 1));
    }
    x[index] = -1;
    y[index] = -1;
    fclose(dataFile);

    // Given data, call algorithm functions
    p11(x, y, index);
    p12(x, y, index);

    // free Q1 data
    free(x);
    free(y);

    // Open the given data_A3_Q2.txt file and extracting the entire text
    strcpy(string, "\0");
    FILE *stringFile = fopen("data_A3_Q2.txt", "r"); // You can change the file name here if you want to use a different one
    if (!stringFile)
    {
        fprintf(stderr, "Error opening file 2\n");
        free(x);
        free(y);
        free(string);
        exit(-1);
    }
    while (fgets(buffer, LENGTH_LIMIT, stringFile))
    {
        int memLen = strlen(buffer);
        totalLen += memLen;
        string = (char *)realloc(string, sizeof(char) * totalLen);
        strcat(string, buffer);
    }
    fclose(stringFile);

    // Algorithm functions
    p21(string);
    p22(string);
    p23(string);

    free(string);

    return 0;
}
