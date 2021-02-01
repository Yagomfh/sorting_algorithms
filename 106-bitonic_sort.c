#include "sort.h"

/**
 * print_sublist - prints sub_list
 * @array: the array source
 * @lo: low index
 * @hi: high index
 * Return: void
 */

void print_sublist(int *array, int lo, int hi)
{
	int i;

	for (i = lo; i <= hi; i++)
	{
		printf("%d", array[i]);
		if (i != hi)
			printf(", ");
		else
			printf("\n");
	}
}

/**
  * comp_swap - compare swap
  * @a: array to use
  * @i: 1st elem
  * @j: 2nd elem
  * @dir: direction to swap
  * Return: void
  */

void comp_swap(int *a, int i, int j, int dir)
{
	int tmp;

	if ((a[i] > a[j] && dir == 1) || (a[i] < a[j] && dir == 0))
	{
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}

/**
  * bitonic_merge - bitonic merge
  * @a: array to use
  * @lo: lower index
  * @cnt: count
  * @dir: direction
  * @ts: original size of array
  * Return: void
  */

void bitonic_merge(int *a, int lo, int cnt, int dir, int ts)
{
	int i, k;

	if (cnt > 1)
	{
		k = cnt / 2;
		for (i = lo; i < lo + k; i++)
			comp_swap(a, i, i + k, dir);
		bitonic_merge(a, lo, k, dir, ts);
		bitonic_merge(a, lo + k, k, dir, ts);
	}
}

/**
  * bitonic - bitonic sorting algorithm
  * @a: array to sort
  * @lo: lower index
  * @cnt: count
  * @dir: direction
  * @ts: original size of array
  * Return: void
  */

void bitonic(int *a, int lo, int cnt, int dir, int ts)
{
	int k;

	if (cnt > 1)
	{
		printf("Merging [%d/%d] ", cnt, ts);
		if (dir == 0)
			printf("(DOWN):\n");
		else
			printf("(UP):\n");
		print_sublist(a, lo, lo + cnt - 1);
		k = cnt / 2;
		bitonic(a, lo, k, 1, ts);
		bitonic(a, lo + k, k, 0, ts);
		bitonic_merge(a, lo, cnt, dir, ts);
		printf("Result [%d/%d] ", cnt, ts);
		if (dir == 0)
			printf("(DOWN):\n");
		else
			printf("(UP):\n");
		print_sublist(a, lo, lo + cnt - 1);
	}
}

/**
  * bitonic_sort - bitonic sorting algo entry point
  * @array: array to sort
  * @size: size of array
  * Return: void
  */

void bitonic_sort(int *array, size_t size)
{
	int s = size, up = 1;

	if (array == NULL || size < 2)
		return;

	bitonic(array, 0, s, up, s);
}
