#include "sort.h"

/**
 * get_max - Get maximum value.
 * @array: array.
 * @size: array size.
 */
int get_max(int *array, int size)
{
	int max, x;

	for (max = array[0], x = 1; x < size; x++)
	{
		if (array[x] > max)
			max = array[x];
	}

	return (max);
}

/**
 * counting_sort - sorts an array of integers in ascending order.
 * @array: array.
 * @size: array size.
 *
 * Description: print the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *int1, *int2, max, x;

	if (array == NULL || size < 2)
		return;

	int2 = malloc(sizeof(int) * size);
	if (int2 == NULL)
		return;
	max = get_max(array, size);
	int1 = malloc(sizeof(int) * (max + 1));
	if (int1 == NULL)
	{
		free(int2);
		return;
	}

	for (x = 0; x < (max + 1); x++)
		int1[x] = 0;
	for (x = 0; x < (int)size; x++)
		int1[array[x]] += 1;
	for (x = 0; x < (max + 1); x++)
		int1[x] += int1[x - 1];
	print_array(int1, max + 1);

	for (x = 0; x < (int)size; x++)
	{
		int2[int1[array[x]] - 1] = array[x];
		int1[array[x]] -= 1;
	}

	for (x = 0; x < (int)size; x++)
		array[x] = int2[x];

	free(int2);
	free(int1);
}
