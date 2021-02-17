#include <stdlib.h>
#include <stdio.h>

#include "sort.h"

/**
 * _merge_sort - initiate merge sort
 *
 * @array: array to be sorted
 * @size: size of the array
 * @temp: temporary array for holding sorted elements
 */
static void _merge_sort(int *array, size_t size, int *temp)
{
	size_t half = size / 2;
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;

	if (size > 1)
	{
		_merge_sort(array, half, temp);
		_merge_sort(array + half, size - half, temp + half);

		printf("Merging...\n");

		printf("[left]: ");
		print_array(array, half);

		printf("[right]: ");
		print_array(array + half, size - half);

		for (k = 0; k < size; k++)
		{
			if (j >= size - half ||
				(i < half && array[i] < (array + half)[j]))
			{
				temp[k] = array[i];
				i++;
			}
			else
			{
				temp[k] = (array + half)[j];
				j++;
			}
		}
		for (k = 0; k < size; k++)
		{
			array[k] = temp[k];
		}
		printf("[Done]: ");
		print_array(array, size);
	}
}

/**
 * merge_sort - initiate merge sort
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp = array && size > 1 ? malloc(sizeof(*temp) * size) : NULL;

	if (temp)
	{
		_merge_sort(array, size, temp);
		free(temp);
	}
}
