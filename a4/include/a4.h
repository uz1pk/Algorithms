/**
 * Usman Zaheer
 * CIS 3490
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAX_WORDS 2045 // pre-set max word instances (as per given file)

typedef struct
{
    int occurrences;
    float probability;
    char word[250];
} Word;

// function executes question 1.1
void p11();

// applies the dynamic programming algorithm of searching through a virtual OBST using mainTable and rootTable
void dynamicSearch(Word *words, char *key, float **probs, int **roots, int row, int col);

// function executes question 1.2
void p12();

// applies the greedy technique algorithm of searching through a virtual OBST using simply the words array and its data
void greedyTechnique(Word *words, char *key, int row, int col);

// function executes question 2
void p2();

// helper function to print the resulting matrix
void printMatrix(int **arr, int size);

// helper function to allocate and initialize the struct array
Word *initializeWordMetadata(int unique);

// helper function to fully parse the data file
// extracts all unique word instances and number of unique words
int getUniqueWords(char *fileName, char *words[]);

// helper compare function for use of C's qsort
int compare(const void *s1, const void *s2);

// the rest of these helpers are for freeing different structures/arrays
void freeWords(char *words[]);
void freeMatrix(int **arr, int size);
void freeMatrixFloat(float **arr, int size);
