#include "sort.h"

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

void bitonic_merge(int *a, int lo, int cnt, int dir)
{
	int i, k;

	if (cnt > 1)
	{
		k = cnt / 2;
		for (i = lo; i < lo + k; i++)
			comp_swap(a, i, i + k, dir);
		bitonic_merge(a, lo, k, dir);
		bitonic_merge(a, lo + k, k, dir);
	}
}

void bitonic(int *a, int lo, int cnt, int dir)
{
	int k;

	if (cnt > 1)
	{
		k = cnt / 2;
		bitonic(a, lo, k, 1);
		bitonic(a, lo + k, k , 0);
		bitonic_merge(a, lo, cnt, dir);
		printf("lo = %d | cnt = %d | dir = %d\n", lo, cnt, dir);
	}
}

void bitonic_sort(int *array, size_t size)
{
	int s = size, up = 1;

	if (array == NULL || size < 2)
		return;

	bitonic(array, 0, s, up);
}
