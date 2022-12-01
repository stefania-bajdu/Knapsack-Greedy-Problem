#include "backpack.h"

backpack *createBackpack(FILE *input)
{
    backpack *heap = (backpack *)malloc(sizeof(backpack));
    int i;
    fscanf(input, "%d%d", &heap->gmax, &heap->N);
    heap->objects = (element *)malloc(heap->N * sizeof(element));
    heap->result = (int *)calloc(heap->N, sizeof(int));
    heap->currentWeight = 0;
    if (heap->objects)
        for (i = 0; i < heap->N; i++)
        {
            heap->objects[i].v = i;
            fscanf(input, "%d%d", &heap->objects[i].g, &heap->objects[i].p);
            heapify_up(heap, i);
        }
    else
    {
        printf("ERROR while allocating memory.\n");
        exit(1);
    }
    return heap;
}

/*
*   Afiseaza in output toate obiectele introduse integral in rucsac.
*/

void printPack(backpack *pack, FILE *output)
{
    int i = 0;
    for (i = 0; i < pack->N; i++)
        if (pack->result[pack->objects[i].v])
            fprintf(output, "object (%d, %d) was added %d times\n", pack->objects[i].g, pack->objects[i].p, pack->result[pack->objects[i].v]);
}

/*
*   Functia returneaza raportul profit-greutate sau eficienta unui obiect.
*/

float efficiency(element x)
{
    return (float)x.p / x.g;
}

/*
*   Eliberarea memoriei
*/

void deleteBackpack(backpack *pack)
{
    free(pack->objects);
    free(pack->result);
    free(pack);
    pack = NULL;
}

/*
*   Deschide un fisier si returneaza un pointer catre fisier.
*/

FILE *openFile(const char *filename, const char *mode)
{
    FILE *file = fopen(filename, mode);
    if (!file)
    {
        printf("Fisierul %s nu a putut fi deschis!", filename);
        exit(1);
    }
    return file;
}