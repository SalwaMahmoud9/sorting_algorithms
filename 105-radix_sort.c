#include "sort.h"

/**
 * get_max - get_max
 * @arr: arr
 * @si: The si of the arr.
 * Return: int
 */
int get_max(int *arr, int si)
{
	int i, max;

	for (max = arr[0], i = 1; i < si; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return (max);
}

/**
 * radix_counting_sort - radix_counting_sort
 * @arr: arr
 * @si: si
 * @sig: sig
 * @buff: buff
 * Return: void
 */
void radix_counting_sort(int *arr, size_t si, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < si; i++)
		count[(arr[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = si - 1; (int)i >= 0; i--)
	{
		buff[count[(arr[i] / sig) % 10] - 1] = arr[i];
		count[(arr[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < si; i++)
		arr[i] = buff[i];
}

/**
 * radix_sort - radix_sort
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int *buff, sig, max;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
