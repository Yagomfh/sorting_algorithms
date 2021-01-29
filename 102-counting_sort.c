#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - counting sorting algo
 * @array: the array to sort
 * @size: size of the array
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int max, i, *counter, cum_count = 0, s = size, flag = 0;

	if (size < 2 || array == NULL)
		return;

	max = array[0];
	for (i = 1; i < s; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	counter = malloc(sizeof(int) * (max + 1));
	if (counter == NULL)
		return;
	for (i = 0; i <= max; i++)
		counter[i] = 0;

	for (i = 0; i < s; i++)
		counter[array[i]] += 1;

	for (i = 0; i <= max; i++)
	{
		cum_count += counter[i];
		counter[i] = cum_count;
	}
	print_array(counter, max + 1);

	for (i = 0; i <= max; i++)
	{
		while (flag < counter[i])
		{
			array[flag] = i;
			flag++;
		}
	}
	free(counter);
}
