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
 * hoare_partition - hoare_partition
 * @arr: arr
 * @si: si
 * @le: le
 * @ri: ri
 * Return: int
 */
int hoare_partition(int *arr, size_t si, int le, int ri)
{
	int piv, abv, bel;

	piv = arr[ri];
	for (abv = le - 1, bel = ri + 1; abv < bel;)
	{
		do {
			abv++;
		} while (arr[abv] < piv);
		do {
			bel--;
		} while (arr[bel] > piv);

		if (abv < bel)
		{
			swap_ints(arr + abv, arr + bel);
			print_array(arr, si);
		}
	}

	return (abv);
}

/**
 * hoare_sort - hoare_sort
 * @arr: arr
 * @si: si
 * @le: le
 * @ri: ri
 * Return: void
 */
void hoare_sort(int *arr, size_t si, int le, int ri)
{
	int prt;

	if (ri - le > 0)
	{
		prt = hoare_partition(arr, si, le, ri);
		hoare_sort(arr, si, le, prt - 1);
		hoare_sort(arr, si, prt, ri);
	}
}

/**
 * quick_sort_hoare - quick_sort_hoare
 * @array: array
 * @size: size
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
