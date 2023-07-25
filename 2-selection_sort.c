#include "sort.h"

/**
 * selection_sort - Sorts array of integers in ascending order using
 * Selection sort algorithm.
 *
 * @array: Pointer to array to be sorted.
 * @size: Size of array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;

			print_array(array, size);
		}
	}
}
