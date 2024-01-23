#include "sort.h"

void swap_ints(int *element1, int *element2);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - max_heapify.
 * @array: array.
 * @size: array size.
 * @base: base.
 * @root: root.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t lft, rght, max;

	lft = 2 * root + 1;
	rght = 2 * root + 2;
	max = root;

	if (lft < base && array[lft] > array[max])
		max = lft;
	if (rght < base && array[rght] > array[max])
		max = rght;

	if (max != root)
	{
		swap_ints(array + root, array + max);
		print_array(array, size);
		max_heapify(array, size, base, max);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order.
 * @array: array.
 * @size: array size.
 *
 * Description: print the array after each time you swap two elements.
 */
void heap_sort(int *array, size_t size)
{
	int x;

	if (array == NULL || size < 2)
		return;

	for (x = (size / 2) - 1; x >= 0; x--)
		max_heapify(array, size, size, x);

	for (x = size - 1; x > 0; x--)
	{
		swap_ints(array, array + x);
		print_array(array, size);
		max_heapify(array, size, x, 0);
	}
}