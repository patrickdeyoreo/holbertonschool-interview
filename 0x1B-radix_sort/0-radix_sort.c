#include <stdlib.h>
#include <limits.h>

#include "sort.h"

/**
 * get_max - get the maximum value of an array of integers
 *
 * @array: pointer to the array from which to get the maximum value
 * @size: number of elements in @array
 *
 * Return: maximum value in @array
 */
int get_max(int const *array, size_t size)
{
	int max = INT_MIN;

	while (size--)
	{
		if (array[size] > max)
			max = array[size];
	}
	return (max);
}

/**
 * _radix_sort - sort an array of integers using LSD radix sort algorithm
 *
 * @array: pointer to array to be sorted
 * @size: number of elements in @array
 * @exp: digit on which elements in @array are to be sorted
 */
void _radix_sort(int *array, int size, int exp)
{
	int *aux = malloc(sizeof(*aux) * size);
	int count[10] = {0};
	int index = 0;

	for (index = 0; index < size; index++)
		count[(array[index] / exp) % 10]++;
	for (index = 1; index < 10; index++)
		count[index] += count[index - 1];
	for (index = size - 1; index >= 0; index--)
	{
		aux[count[(array[index] / exp) % 10] - 1] = array[index];
		count[(array[index] / exp) % 10]--;
	}
	for (index = 0; index < size; index++)
		array[index] = aux[index];
	print_array(array, size);
	free(aux);
}

/**
 * radix_sort - sort an array of integers using a LSD radix sort algorithm
 *
 * @array: pointer to the array to be sorted
 * @size: number of elements in @array
 *
 * Description: Sort an array of integers in place in ascending order.
 */
void radix_sort(int *array, size_t size)
{
	int exp = 1;
	int max = INT_MIN;

	if (array && size > 1)
	{
		for (max = get_max(array, size); max / exp; exp *= 10)
			_radix_sort(array, size, exp);
	}
}
