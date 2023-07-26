#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * getMax - Helper func to get max value in array
 * @array: Pointer to array
 * @size: array size
 * Return: max value in array
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	return (max);
}

/**
 * countingSort - Helper func to do counting sort on array
 * @array: Pointer to array
 * @size: array size
 * @exp: current digit to sort by
 */
void countingSort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(output);
}

/**
 * radix_sort - algorithm to sort array of ints in ascending order
 * @array: Pointer to array
 * @size: Size of array
 */
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
		print_array(array, size);
	}
}
