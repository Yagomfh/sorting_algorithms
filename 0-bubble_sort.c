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

/**
  * bubble_sort - bubble sort algo
  * @array: the array to sort
  * @size: size of the array
  * Return: void
  */

void bubble_sort(int *array, size_t size)
{
	size_t cmp = 1, i;

	if (size < 2)
		return;

	while (cmp != 0)
	{
		i = 1;
		cmp = 0;
		while (i < size)
		{
			if (array[i - 1] > array[i])
			{
				swap_array(array, i - 1, i);
				cmp = 1;
				print_array(array, size);
			}
			i++;
		}
	}
}
