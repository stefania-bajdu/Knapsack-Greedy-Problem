#include "backpack.h"

int main(int argc, char **argv)
{
    backpack *pack;
    int i = 0, j;
    FILE *input, *output;
    element *root, *arr;
    input = openFile(argv[1], "rt");
    output = openFile(argv[2], "wt");
    pack = createBackpack(input);
    fclose(input);
    arr = (element *)malloc(pack->N * sizeof(element));
    while (pack->currentWeight <= pack->gmax)
    {
        while (pack->N)
        {
            root = deleteRoot(pack);
            arr[i++] = *root;
            if (pack->currentWeight + root->g <= pack->gmax)
            {
                pack->result[root->v]++;
                pack->currentWeight += root->g;
            }
            else
                goto escape;
        }
        for (j = 0; j < i; j++)
            insert(pack, &arr[j]);
        i = 0;
    }
escape:
    for (j = 0; j < i; j++)
        insert(pack, &arr[j]);
    printPack(pack, output);

    int difference = pack->gmax - pack->currentWeight;
    float profit = difference * efficiency(arr[i - 1]);
    if (difference)
    {
        fprintf(output, "----------------------------------------------\n");
        fprintf(output, "object (%d, %d) needs to be cut by %.2f\n", arr[i - 1].g, arr[i - 1].p, (float)difference / arr[i - 1].g);
        fprintf(output, "fractioned object was added with (%d, %.2f)\n", difference, profit);
    }
    for (i = 0; i < pack->N; i++)
        if (pack->result[pack->objects[i].v])
            profit += pack->result[pack->objects[i].v] * pack->objects[i].p;
    fprintf(output, "----------------------------------------------\n");
    fprintf(output, "maximum profit is %.2f", profit);
    fclose(output);
    deleteBackpack(pack);
    return 0;
}