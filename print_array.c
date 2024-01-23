#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - print array.
 *
 * @array: array.
 * @size: array sizes.
 */
void print_array(const int *array, size_t size)
{
    size_t x;

    x = 0;
    while (array && x < size)
    {
        if (x > 0)
            printf(", ");
        printf("%d", array[x]);
        ++x;
    }
    printf("\n");
}
