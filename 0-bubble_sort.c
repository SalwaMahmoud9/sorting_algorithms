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
 * bubble_sort - sorts an array of integers in ascending order.
 * @array: array.
 * @size: array size.
 *
 * Description: print the array after each time you swap two elements.
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, y = size;
	bool status = false;

	if (array == NULL || size < 2)
		return;

	while (status == false)
	{
		status = true;
		for (x = 0; x < y - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				swap_ints(array + x, array + x + 1);
				print_array(array, size);
				status = false;
			}
		}
		y--;
	}
}
