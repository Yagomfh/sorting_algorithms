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
  * merge - merges sub-entities
  * @array: array to sort
  * @tab: temporal array
  * @lo: high index
  * @hi: low index
  * @mid: mid index
  * Return: void
  */

void merge(int *array, int *tab, int lo, int hi, int mid)
{
	int i = lo, j = mid + 1, k = 0;

	printf("Merging...\n[left]: "), print_sublist(array, lo, mid);
	printf("[right]: "), print_sublist(array, mid + 1, hi);
	while (i <= mid && j <= hi)
	{
		if (array[i] < array[j])
		{
			tab[k] = array[i];
			i++;
		}
		else
		{
			tab[k] = array[j];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		tab[k] = array[i];
		i++;
		k++;
	}
	while (j <= hi)
	{
		tab[k] = array[j];
		j++;
		k++;
	}
	for (i = lo; i <= hi; i++)
		array[i] = tab[i - lo];
	printf("[Done]: "), print_sublist(array, lo, hi);
}

/**
  * merge_sort_n - main merge sorting algo
  * @array: array to sort
  * @tab: temp array
  * @lo: low index
  * @hi: high index
  * Return: void
  */

void merge_sort_n(int *array, int *tab, int lo, int hi)
{
	int mid = (hi + lo - 1) / 2;

	if (lo < hi)
	{
		merge_sort_n(array, tab, lo, mid);
		merge_sort_n(array, tab, mid + 1, hi);
		merge(array, tab, lo, hi, mid);
	}
}

/**
 * merge_sort - merge sorting algo
 * @array: the array to sort
 * @size: size of the array
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *tab;

	if (size < 2 || array == NULL)
		return;

	tab = malloc(sizeof(int) * size);
	if (tab == NULL)
		return;
	merge_sort_n(array, tab, 0, size - 1);
	free(tab);
}
