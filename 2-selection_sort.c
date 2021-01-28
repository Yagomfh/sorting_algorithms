#include "sort.h"

/**
 * swap_array - swaps array elements
 * @array: the array
 * @i: elem 1 to swap
 * @j: elem 2 to swap
 * Return: void
 */

void swap_array(int *array, int i, int j)
{
	int tmp = array[i];

	array[i] = array[j];
	array[j] = tmp;
}

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, min;

	if (size < 2)
		return;

	while (i < size - 1)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap_array(array, i, min);
			print_array(array, size);
		}
		i++;
	}
}
