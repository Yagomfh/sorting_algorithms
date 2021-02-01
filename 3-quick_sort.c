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
  * partition - takes last element as pivot, places
  * the pivot element at its correct position
  * places all smaller to left of pivot and all greater elements to right
  * of pivot
  * @array: the array to parse
  * @lo: starting index
  * @hi: ending index
  * @size: size of the array
  * Return: index of smaller element
  */

int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo, j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap_array(array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != hi)
	{
		swap_array(array, i, hi);
		print_array(array, size);
	}
	return (i);
}

/**
  * qs - implements quick sort
  * @array: array to sort
  * @lo: starting index
  * @hi: ending index
  * @size: size of the array;
  * Return: void
  */

void qs(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		qs(array, lo, p - 1, size);
		qs(array, p + 1, hi, size);
	}
}

/**
  * quick_sort - quick sort function
  * @array: array to sort
  * @size: size of the array
  * Return: void
  */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
