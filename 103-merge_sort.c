#include "sort.h"
#include <stdio.h>
/**
 * print_data - print_data
 * @message: message
 * @arr: array
 * @f: f
 * @t: t
 * Return: void
 */
void print_data(char *message, int *arr, int f, int t)
{
	char *s;
	int index;

	printf("[%s]: ", message);
	s = "";

	for (index = f; index <= t; index++)
	{
		printf("%s%d", s, arr[index]);
		s = ", ";
	}
	printf("\n");
}

/**
 * merge - merge
 * @arr: array
 * @l: l
 * @m: m
 * @h: h
 * @buff: buff
 * Return: void
 */
void merge(int *arr, int l, int m, int h, int *buff)
{
	int loo, lmm, index;

	loo = index = l;
	lmm = m + 1;

	printf("Merging...\n");
	print_data("left", arr, l, m);
	print_data("right", arr, m + 1, h);

	while (loo <= m && lmm <= h)
	{
		if (arr[loo] < arr[lmm])
			buff[index++] = arr[loo++];
		else
			buff[index++] = arr[lmm++];
	}

	while (loo <= m)
		buff[index++] = arr[loo++];

	while (lmm <= h)
		buff[index++] = arr[lmm++];

	for (index = l; index <= h; index++)
		arr[index] = buff[index];

	print_data("Done", arr, l, h);
}
/**
 * msort -msort
 * @arr: array
 * @l: l
 * @h: h
 * @buff: buff
 * Return: void
 */
void msort(int *arr, int l, int h, int *buff)
{
	int mi;

	if (l < h)
	{
		mi = (l + h - 1) / 2;
		msort(arr, l, mi, buff);
		msort(arr, mi + 1, h, buff);
		merge(arr, l, mi, h, buff);
	}
}
/**
 * merge_sort -merge_sort
 * @array: array
 * @size: size
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	buff = malloc(sizeof(int) * size);
	if (!buff)
		return;
	msort(array, 0, size - 1, buff);
	free(buff);
}
