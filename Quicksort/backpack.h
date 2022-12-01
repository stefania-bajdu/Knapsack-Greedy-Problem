#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int v;
    int g, p;
} element;

typedef struct backpack
{
    int gmax, N;
    int currentWeight;
    element *objects; //vectorul celor N obiecte
    int *result;
} backpack;

backpack *createBackpack(FILE *);
void deleteBackpack(backpack *);
void swap(element *, element *);
float efficiency(element);
void printPack(backpack *, FILE *);
int partition(element *, int, int);
void quicksort(element *, int, int);
FILE *openFile(const char *, const char *);