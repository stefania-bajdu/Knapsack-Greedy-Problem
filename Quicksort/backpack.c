#include "backpack.h"

backpack *createBackpack(FILE *input)
{
    backpack *pack = (backpack *)malloc(sizeof(backpack));
    int i;
    fscanf(input, "%d%d", &pack->gmax, &pack->N);
    pack->objects = (element *)malloc(pack->N * sizeof(element));
    pack->result = (int *)calloc(pack->N, sizeof(int));
    pack->currentWeight = 0;
    if (pack->objects)
        for (i = 0; i < pack->N; i++)
        {
            pack->objects[i].v = i;
            fscanf(input, "%d%d", &pack->objects[i].g, &pack->objects[i].p);
        }
    else
    {
        printf("ERROR while allocating memory.\n");
        exit(1);
    }
    quicksort(pack->objects, 0, pack->N - 1);
    return pack;
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