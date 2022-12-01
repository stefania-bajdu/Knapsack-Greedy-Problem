#include "backpack.h"

int main(int argc, char **argv)
{
    backpack *pack;
    int i = 0;
    FILE *input, *output;
    input = openFile(argv[1], "rt");
    output = openFile(argv[2], "wt");
    pack = createBackpack(input);
    fclose(input);
    while (pack->currentWeight <= pack->gmax)
    {
        if (i == pack->N)
            i = 0;
        if (pack->currentWeight + pack->objects[i].g <= pack->gmax)
        {
            pack->result[pack->objects[i].v]++;
            pack->currentWeight += pack->objects[i++].g;
        }
        else
            break;
    }
    printPack(pack, output);
    
    int difference = pack->gmax - pack->currentWeight;
    float profit = difference * efficiency(pack->objects[i]);
    if (difference)
    {
        fprintf(output, "----------------------------------------------\n");
        fprintf(output, "object (%d, %d) needs to be cut by %.2f\n", pack->objects[i].g, pack->objects[i].p,(float)difference/pack->objects[i].g);
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
