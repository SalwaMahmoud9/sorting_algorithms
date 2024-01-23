#include "sort.h"
#include <stdio.h>

/**
 * printcheck - print range.
 * @array: array.
 * @r1: range.
 * @r2: range.
 */
void printcheck(int *array, int r1, int r2)
{
	int x;

	for (x = r1; x <= r2; x++)
	{
		if (x > r1)
			printf(", ");
		printf("%d", array[x]);
	}
	printf("\n");
}
/**
 * _swap - swap.
 * @array: array.
 * @x: index.
 * @y: index.
 * @dir: direction.
 */
void _swap(int *array, int x, int y, int dir)
{
	int temp;

	if (dir == (array[x] > array[y]))
	{
		temp = array[x];
		array[x] = array[y];
		array[y] = temp;
	}
}
/**
 * bitonic_merge - bitonic_merge.
 * @array: array.
 * @low: low element.
 * @size: size.
 * @dir: direction.
 * @r_size: size.
 */
void bitonic_merge(int *array, int low, int size, int dir, const int r_size)
{
	int x = size, y = low;

	if (size > 1)
	{
		x = size / 2;

		for (y = low; y < low + x; y++)
			_swap(array, y, y + x, dir);

		bitonic_merge(array, low, x, dir, r_size);
		bitonic_merge(array, low + x, x, dir, r_size);
	}
}
/**
 * _sort - sort.
 * @array: array.
 * @low: lowest element.
 * @size: size.
 * @dir: direction.
 * @r_size: size.
 */
void _sort(int *array, int low, int size, int dir, const int r_size)
{
	int x = size;

	if (size > 1)
	{
		if (dir == 1)
			printf("Merging [%d/%d] (UP):\n", size, r_size);
		if (dir == 0)
			printf("Merging [%d/%d] (DOWN):\n", size, r_size);
		printcheck(array, low, low + x - 1);

		x = size / 2;
		_sort(array, low, x, 1, r_size);

		_sort(array, low + x, x, 0, r_size);

		bitonic_merge(array, low, size, dir, r_size);
		if (dir == 1)
		{
			printf("Result [%d/%d] (UP):\n", size, r_size);
			printcheck(array, low, low + 2 * x - 1);
		}
		if (dir == 0)
		{
			printf("Result [%d/%d] (DOWN):\n", size, r_size);
			printcheck(array, low, low + 2 * x - 1);
		}
	}
}
/**
 * bitonic_sort - sorts an array of integers in ascending order.
 * @array: array.
 * @size: array size.
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;
	const int r_size = (int)size;

	if (size < 2 || !array)
		return;

	_sort(array, 0, (int)size, up, r_size);
}