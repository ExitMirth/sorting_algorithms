#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - Swaps two elements in an array.
 * @a: Pointer to first element.
 * @b: Pointer to second element.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - Merges two subarrays in ascending or descending order.
 * @array: The array to be sorted.
 * @low: Starting index of first subarray.
 * @count: Num of elements in subarrays.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	size_t k = count / 2;
	size_t i;

	if (count <= 1)
		return;

	for (i = low; i < low + k; i++)
	{
		if (dir == (array[i] > array[i + k]))
			swap(&array[i], &array[i + k]);
	}

	bitonic_merge(array, low, k, dir);
	bitonic_merge(array, low + k, k, dir);
}

/**
 * bitonic_sort_recursive - Recursively performs Bitonic sort.
 * @array: Array to be sorted.
 * @low: Starting index of subarray.
 * @count: Number of elements in subarray.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	size_t k;

	if (count <= 1)
		return;

	k = count / 2;

	printf("Merging [%lu/%lu] (%s):\n", count, count * 2, dir ? "UP" : "DOWN");
	print_array(array + low, count);

	bitonic_sort_recursive(array, low, k, 1);
	bitonic_sort_recursive(array, low + k, k, 0);
	bitonic_merge(array, low, count, dir);

	printf("Result [%lu/%lu] (%s):\n", count, count * 2, dir ? "UP" : "DOWN");
	print_array(array + low, count);
}

/**
 * bitonic_sort - Sorts array of integers in ascending order using Bitonic sort
 * @array: Array to be sorted.
 * @size: Size of array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 1);
}
