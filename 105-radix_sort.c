#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - Sorts array of ints in ascending order using Radix sort.
 * @array: Array to be sorted.
 * @size: Size of array.
 */
void radix_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int max_value = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max_value)
            max_value = array[i];
    }

    int exp = 1;
    int *output = malloc(size * sizeof(int));
    if (output == NULL)
        return;

    while (max_value / exp > 0) {
        int count[10] = {0};

        for (size_t i = 0; i < size; i++)
            count[(array[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; i >= 0; i--)
            output[--count[(array[i] / exp) % 10]] = array[i];

        for (size_t i = 0; i < size; i++)
            array[i] = output[i];

        print_array(array, size);
        exp *= 10;
    }

    free(output);
}
