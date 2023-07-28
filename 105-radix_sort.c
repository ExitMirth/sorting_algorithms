#include "sort.h"
#include <stdlib.h>

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int max_value;
	int exp = 1;
	int *output;
	int count[10] = {0};

	if (array == NULL || size < 2)
		return;

	max_value = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	output = (int *)malloc(size * sizeof(int));

	if (output == NULL)
		return;

	while (max_value / exp > 0)
	{
		for (i = 0; i < size; i++)
			count[(array[i] / exp) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size; i > 0; i--)
			output[--count[(array[i - 1] / exp) % 10]] = array[i - 1];

		for (i = 0; i < size; i++)
			array[i] = output[i];

		print_array(array, size);
		exp *= 10;
	}

	free(output);
}
