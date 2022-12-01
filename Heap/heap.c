#include "backpack.h"

void swap(element *x, element *y)
{
    element temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void heapify_down(backpack *heap, int i)
{
    int left, right, max;
    max = i;
    while (i < heap->N)
    {
        left = leftChild(heap, i);
        right = rightChild(heap, i);
        if (left != -1 && efficiency(heap->objects[left]) > efficiency(heap->objects[max]))
            max = left;
        if (right != -1 && efficiency(heap->objects[right]) > efficiency(heap->objects[max]))
            max = right;
        if (max != i)
        {
            swap(&heap->objects[i], &heap->objects[max]);
            i = max;
        }
        else
            break;
    }
}

void heapify_up(backpack *heap, int i)
{
    int indice = parent(heap, i);
    while (indice != -1 && efficiency(heap->objects[indice]) < efficiency(heap->objects[i]))
    {
        swap(&heap->objects[i], &heap->objects[indice]);
        i = indice;
        indice = parent(heap, i);
    }
}

element *deleteRoot(backpack *heap)
{
    element *data = (element *)malloc(sizeof(element));

    *data = heap->objects[0];
    heap->objects[0] = heap->objects[heap->N - 1];
    heap->objects[heap->N - 1] = *data;

    heap->N--;
    heapify_down(heap, 0);
    return data;
}

void insert(backpack *heap, element *x)
{
    heap->N++;
    heap->objects[heap->N - 1] = *x;
    heapify_up(heap, heap->N - 1);
}

int rightChild(backpack *heap, int i)
{
    int position = 2 * i + 2;
    if (position > heap->N - 1 || i < 0)
        return -1;
    return position;
}

int leftChild(backpack *heap, int i)
{
    int position = 2 * i + 1;
    if (position > heap->N - 1 || i < 0)
        return -1;
    return position;
}

int parent(backpack *heap, int i)
{
    if (i > heap->N - 1 || i <= 0)
        return -1;
    return (i - 1) / 2;
}