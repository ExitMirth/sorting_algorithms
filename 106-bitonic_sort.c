#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *array, size_t size, int up, size_t i);
void bitonic_merge(int *array, size_t size, int up);
void bitonic_sort_recursive(int *array, size_t size, int up, size_t step);
void copy_array(int *dest, int *src, size_t size);

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *                the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, size, 1, size);
}

/**
 * swap - Swaps two elements in an array.
 * @array: The array containing the elements.
 * @size: The size of the array.
 * @up: A flag indicating whether to sort in ascending or descending order.
 * @i: Index of the first element to swap.
 */
void swap(int *array, size_t size, int up, size_t i)
{
	int temp;

	if ((array[i] > array[i + size / 2]) == up)
	{
		temp = array[i];
		array[i] = array[i + size / 2];
		array[i + size / 2] = temp;
	}
}

/**
 * bitonic_merge - Merges two sub-arrays in bitonic order.
 * @array: The array containing the sub-arrays to merge.
 * @size: The size of each sub-array.
 * @up: A flag indicating whether to sort in ascending or descending order.
 */
void bitonic_merge(int *array, size_t size, int up)
{
	if (size > 1)
	{
		size_t i;
		size_t mid = size / 2;

		for (i = 0; i < mid; i++)
			swap(array, size, up, i);

		bitonic_merge(array, mid, up);
		bitonic_merge(array + mid, mid, up);
	}
}

/**
 * bitonic_sort_recursive - Sorts an array of integers using the Bitonic sort
 *                          algorithm recursively.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @up: A flag indicating whether to sort in ascending or descending order.
 * @step: The current step in the sorting process.
 */
void bitonic_sort_recursive(int *array, size_t size, int up, size_t step)
{
	if (size > 1)
	{
		size_t mid = size / 2;

		bitonic_sort_recursive(array, mid, 1, step);
		bitonic_sort_recursive(array + mid, mid, 0, step);
		bitonic_merge(array, size, up);
	}
}

/**
 * copy_array - Copies elements from one array to another.
 * @dest: The destination array.
 * @src: The source array.
 * @size: The number of elements to copy.
 */
void copy_array(int *dest, int *src, size_t size)
{
	size_t i;
	for (i = 0; i < size; i++)
		dest[i] = src[i];
}

/**
 * bitonic - Sorts an array of integers in ascending order using
 *           the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic(int *array, size_t size)
{
	int *temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	copy_array(temp, array, size);
	bitonic_sort(temp, size);
	print_array(temp, size);
	free(temp);
}
