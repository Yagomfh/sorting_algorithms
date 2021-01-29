#include "sort.h"

/**
  * get_max_digits - gets max digit in list
  * @a: array to parse
  * @s: size of the array
  * Return: max nb of digits
  */

int get_max_digits(int *a, size_t s)
{
	size_t i = 1;
	int max = a[0], digits = 0;

	while (i < s)
	{
		if (a[i] > max)
			max = a[i];
		i++;
	}
	while (max != 0)
	{
		digits++;
		max /= 10;
	}
	return (digits);
}

/**
  * count_sort - count sort for digits
  * @a: array to sort
  * @size: size of the array
  * @i: index of digit to sort
  * Return: void
  */

void count_sort(int *a, size_t size, int i)
{
	int count[10] = {0};
	int *output, j, s = size;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	for (j = 0; j < s; j++)
		count[(a[j] / i) % 10] += 1;

	for (j = 1; j < 10; j++)
		count[j] += count[j - 1];

	for (j = size - 1; j >= 0; j--)
	{
		output[count[(a[j] / i) % 10] - 1] = a[j];
		count[(a[j] / i) % 10] -= 1;
	}
	for (j = 0; j < s; j++)
		a[j] = output[j];
	print_array(output, size);
	free(output);
}

/**
  * radix_sort - radix sort algo
  * @array: array to sort
  * @size: size of the array
  * Return: void
  */

void radix_sort(int *array, size_t size)
{
	int digits, i = 1;

	if (array == NULL || size < 2)
		return;

	digits = get_max_digits(array, size);

	while (digits > 0)
	{
		count_sort(array, size, i);
		i *= 10;
		digits--;
	}
}
