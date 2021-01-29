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
  * max - max num in binary tree
  * @a: the array
  * @n: leght of array
  * @i: index
  * @j: level1
  * @k: level2
  * Return: max num
  */

int max(int *a, int n, int i, int j, int k)
{
	int m = i;

	if (j < n && a[j] > a[m])
		m = j;

	if (k < n && a[k] > a[m])
		m = k;

	return (m);
}

/**
  * down_heap - bin sort
  * @array: array to sort
  * @size: size of array
  * @i: index
  * @max_s: total size array
  * Return: void
  */

void down_heap(int *array, size_t size, int i, int max_s)
{
	int j;

	while (1)
	{
		j = max(array, size, i, 2 * i + 1, 2 * i + 2);
		if (j == i)
			break;
		swap_array(array, i, j);
		print_array(array, max_s);
		i = j;
	}
}

/**
 * heap_sort - heap sorting algo
 * @array: the array to sort
 * @size: size of the array
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	int i, n = size;

	for (i = (n - 2) / 2; i >= 0; i--)
		down_heap(array, size, i, n);

	for (i = 0; i < n - 1; i++)
	{
		swap_array(array, 0, size - i - 1);
		print_array(array, size);
		down_heap(array, size - i - 1, 0, n);
	}
}
