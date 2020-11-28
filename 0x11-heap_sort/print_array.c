#include <stdio.h>

#include "sort.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i = 0;

	if (array)
	{
		while (i < size)
		{
			printf("%d", array[i++]);
			if (i < size)
				printf(", ");
		}
	}
	printf("\n");
}
