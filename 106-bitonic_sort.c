#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: First element
 * @b: Second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * bitonic_merge - Merges two subarrays in bitonic order
 * @array: Pointer to the array
 * @low: Starting index of the first subarray
 * @count: Number of elements to be merged
 * @up: Direction of merge (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int up)
{
    if (count > 1)
    {
        size_t k = count / 2;
        size_t i;

        for (i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == up)
                swap(&array[i], &array[i + k]);
        }

        bitonic_merge(array, low, k, up);
        bitonic_merge(array, low + k, k, up);
    }
}

/**
 * bitonic_sort_recursive - Recursive function for bitonic sort
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the range to be sorted
 * @count: Number of elements to be sorted
 * @up: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int up)
{
    if (count > 1)
    {
        size_t k = count / 2;

        printf("Merging [%lu/%lu] (%s):\n", count, count * 2, up ? "UP" : "DOWN");
        print_array(array + low, count);

        bitonic_sort_recursive(array, low, k, 1);
        bitonic_sort_recursive(array, low + k, k, 0);

        bitonic_merge(array, low, count, up);

        printf("Result [%lu/%lu] (%s):\n", count, count * 2, up ? "UP" : "DOWN");
        print_array(array + low, count);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, 0, size, 1);
}
