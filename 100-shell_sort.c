#include "sort.h"

/**
 * swap_ints - Swap integers.
 * @element1: element 1.
 * @element2: element 2.
 */
void swap_ints(int *element1, int *element2)
{
	int temp;

	temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}

/**
 * shell_sort - sorts an array of integers in ascending order.
 * @array: array.
 * @size: array size.
 *
 * Description: print the array each time you decrease the interval.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, x, y;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (x = gap; x < size; x++)
		{
			y = x;
			while (y >= gap && array[y - gap] > array[y])
			{
				swap_ints(array + y, array + (y - gap));
				y -= gap;
			}
		}
		print_array(array, size);
	}
}