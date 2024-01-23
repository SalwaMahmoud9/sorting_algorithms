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
 * selection_sort - sorts an array of integers in ascending order.
 * @array: array.
 * @size: array size.
 *
 * Description:  print the array after each time you swap two elements.
 */
void selection_sort(int *array, size_t size)
{
	int *int1;
	size_t x, y;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		int1 = array + x;
		for (y = x + 1; y < size; y++)
			int1 = (array[y] < *int1) ? (array + y) : int1;

		if ((array + x) != int1)
		{
			swap_ints(array + x, int1);
			print_array(array, size);
		}
	}
}