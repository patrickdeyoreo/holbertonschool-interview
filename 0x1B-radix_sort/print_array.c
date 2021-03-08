#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - print an array of integers
 *
 * @array: pointer to the array to be printed
 * @size: number of elements in @array
 */
void print_array(int const *array, size_t size)
{
	if (array)
	{
		while (size--)
		{
			printf("%d", *array++);
			if (size)
				printf(", ");
		}
		printf("\n");
	}
}
