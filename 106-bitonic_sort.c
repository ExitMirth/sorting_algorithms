#include "sort.h"

/**
 * bitonic_compare - Compares two elements based on the direction.
 *
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 * @a: First element to compare.
 * @b: Second element to compare.
 */
void bitonic_compare(int dir, int *a, int *b)
{
    if ((dir && *a > *b) || (!dir && *a < *b))
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

/**
 * bitonic_merge - Merges the array in the specified order.
 *
 * @array: Array to merge.
 * @low: Starting index.
 * @count: Number of elements to merge.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t mid = count / 2;
        size_t i;

        for (i = low; i < low + mid; i++)
            bitonic_compare(dir, &array[i], &array[i + mid]);

        bitonic_merge(array, low, mid, dir);
        bitonic_merge(array, low + mid, mid, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *                using the Bitonic sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    bitonic_sort_recursive(array, 0, size, 1);
}

/**
 * bitonic_sort_recursive - Recursively sorts the array.
 *
 * @array: The array to be sorted.
 * @low: Starting index.
 * @count: Number of elements to sort.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t mid = count / 2;

        bitonic_sort_recursive(array, low, mid, !dir);
        bitonic_sort_recursive(array, low + mid, mid, dir);
        bitonic_merge(array, low, count, dir);
    }
}
