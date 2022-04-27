/**
 * Usman Zaheer
 * CIS 3490
 **/

#include "a4.h"

void p2()
{
    FILE *p;
    int **men;
    int **women;
    int **resultMatrix;
    char buffer[300];
    int size, matched, memLen, row, col, i, temp;

    // prompt filename
    printf("Enter Filename\n");
    fgets(buffer, 300, stdin);
    memLen = strlen(buffer);
    buffer[memLen - 1] = '\0';

    // parse file data and store it accordingly
    p = fopen(buffer, "r");
    if (!p)
    {
        fprintf(stderr, "File does not exist\n");
        return;
    }

    fscanf(p, "%d", &size); // get size
    matched = size;

    men = (int **)malloc(sizeof(int *) * size);
    women = (int **)malloc(sizeof(int *) * size);
    resultMatrix = (int **)malloc(sizeof(int *) * size);
    int freeMen[size];
    int freeWomen[size];

    for (i = 0; i < size; i++)
    {
        men[i] = (int *)malloc(sizeof(int));
        women[i] = (int *)malloc(sizeof(int));
        resultMatrix[i] = (int *)malloc(sizeof(int));
        freeMen[i] = -1;
        freeWomen[i] = -1;
        for (temp = 0; temp < size; temp++)
        {
            resultMatrix[i][temp] = 0;
        }
    }

    row = 0;
    while (row != size)
    {
        col = 0;
        fgets(buffer, 300, p);
        while (col != size)
        {
            fscanf(p, "%d", &(men[row][col++]));
        }
        row++;
    }

    row = 0;
    while (row != size)
    {
        col = 0;
        fgets(buffer, 300, p);
        while (col != size)
        {
            fscanf(p, "%d", &(women[row][col++]));
        }
        row++;
    }
    fclose(p); // parsing finished

    // while there remains un-matched couples, continue matching according to algorithm
    while (matched > 0)
    {
        int firstMale;
        for (firstMale = 0; firstMale < size; firstMale++)
        {
            if (freeMen[firstMale] == -1)
            {
                break;
            }
        }

        int womanIndex;
        for (womanIndex = 0; freeMen[firstMale] == -1 && womanIndex < size; womanIndex++)
        {
            int currWoman = men[firstMale][womanIndex] - 1;
            if (freeWomen[currWoman] == -1)
            {
                freeWomen[currWoman] = firstMale;
                freeMen[firstMale] = currWoman;
                resultMatrix[firstMale][currWoman] = 1;
                matched--;
            }
            else
            {
                int isBetter = 0;
                int currentMale = freeWomen[currWoman];
                for (temp = 0; temp < size; temp++)
                {
                    if (women[currWoman][temp] == currentMale + 1)
                    {
                        break;
                    }
                    else if (women[currWoman][temp] == firstMale + 1)
                    {
                        isBetter = 1;
                        break;
                    }
                }
                if (isBetter)
                {
                    freeMen[currentMale] = -1;
                    freeMen[firstMale] = currWoman;
                    freeWomen[currWoman] = firstMale;
                    resultMatrix[firstMale][currWoman] = 1;
                    resultMatrix[currentMale][currWoman] = 0;
                }
            }
        }
    }

    printMatrix(resultMatrix, size);
    freeMatrix(men, size);
    freeMatrix(women, size);
    freeMatrix(resultMatrix, size);
}

// print the result matrix
void printMatrix(int **arr, int size)
{
    printf("Output:\n\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// driver function
int main()
{
    p2();

    return 0;
}
