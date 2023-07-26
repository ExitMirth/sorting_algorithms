#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * getMax - Helper func to get max value in array
 */
int getMax(int *array, size_t size) {
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

/**
 * countingSort - Helper func to do counting sort on array
 */
void countingSort(int *array, size_t size, int exp) {
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};

    for (size_t i = 0; i < size; i++) {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (size_t i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(output);
}

/**
 * radix_sort - algorithm sorts array of ints in ascending order
 */
void radix_sort(int *array, size_t size) {
    int max = getMax(array, size);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(array, size, exp);
        print_array(array, size);
    }
}
