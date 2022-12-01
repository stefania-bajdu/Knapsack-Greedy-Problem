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
int parent(backpack *, int);
int leftChild(backpack *, int);
int rightChild(backpack *, int);
void heapify_up(backpack *, int);
void heapify_down(backpack *, int);
element *deleteRoot(backpack *);
void insert(backpack *, element *);
FILE *openFile(const char *, const char *);