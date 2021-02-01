#include "sort.h"

/**
  * shell_sort - shell sorting algo
  * @array: array to sort
  * @size: size of the array
  * Return: void
  */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, j, i;
	int tmp;

	if (size < 2)
		return;

	while (gap * 3 + 1 < size)
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		gap /= 3;
		print_array(array, size);
	}
}
