#include "sort.h"

/**
 * swap_ints - Swap integers.
 * @element1: element 1.
 * @element2: element 2.
 */
void swap_ints(int *element1, int *element2)
{
	int tmp;

	tmp = *element1;
	*element1 = *element2;
	*element2 = tmp;
}


/**
 * lomuto_partition - lomuto_partition
 * @arr: arr
 * @si: si
 * @le: le
 * @ri: ri
 * Return: int
 */
int lomuto_partition(int *arr, size_t si, int le, int ri)
{
	int *pv, abv, bel;

	pv = arr + ri;
	for (abv = bel = le; bel < ri; bel++)
	{
		if (arr[bel] < *pv)
		{
			if (abv < bel)
			{
				swap_ints(arr + bel, arr + abv);
				print_array(arr, si);
			}
			abv++;
		}
	}

	if (arr[abv] > *pv)
	{
		swap_ints(arr + abv, pv);
		print_array(arr, si);
	}

	return (abv);
}

/**
 * lomuto_sort - lomuto_sort
 * @arr: arr
 * @si: si
 * @le: le
 * @ri: ri
 * Return: void
 */
void lomuto_sort(int *arr, size_t si, int le, int ri)
{
	int part;

	if (ri - le > 0)
	{
		part = lomuto_partition(arr, si, le, ri);
		lomuto_sort(arr, si, le, part - 1);
		lomuto_sort(arr, si, part + 1, ri);
	}
}

/**
 * quick_sort - quick_sort
 * @array: array
 * @size: size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
