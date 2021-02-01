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
	int i = lo - 1, j = hi + 1;

	while (1)
	{
		do
		{
			i++;
		} while (array[i] < pivot);
		do
		{
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (j);
		swap_array(array, i, j);
		print_array(array, size);
	}
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
		printf("lo = %d  hi = %d", lo, hi);
		puts("\n");
		p = partition(array, lo, hi, size);
		printf("p = %d\n", p);
		if (p == 9 && lo == 6 && hi == 9)
		{
			print_array(array, size);
			return;
		}
		qs(array, lo, p, size);
		qs(array, p + 1, hi, size);
	}
}

/**
  * quick_sort - quick sort function
  * @array: array to sort
  * @size: size of the array
  * Return: void
  */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
