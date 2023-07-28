#include "sort.h"
#include <stdlib.h>

/**
 * count_sort - Performs counting sort on an array according to digit position
 * @array: Array to be sorted.
 * @size: Size of array.
 * @exp: Digit position to sort by.
 * @output: Output array to store sorted elements.
 */
void count_sort(int *array, size_t size, int exp, int *output)
{
	size_t i;
	int count[10] = {0};

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
		output[--count[(array[i - 1] / exp) % 10]] = array[i - 1];

	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of ints in ascending order using Radix sort.
 * @array: Array to be sorted.
 * @size: Size of array.
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int max_value;
	int exp = 1;
	int *output;

	if (array == NULL || size < 2)
		return;

	output = (int *)malloc(size * sizeof(int));

	if (output == NULL)
		return;

	max_value = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	while (max_value / exp > 0)
	{
		count_sort(array, size, exp, output);
		print_array(array, size);
		exp *= 10;
	}

	free(output);
}
