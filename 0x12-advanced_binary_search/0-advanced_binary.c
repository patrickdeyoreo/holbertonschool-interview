#include <stdio.h>

#include "search_algos.h"

/**
 * _print_slice - print the values in an array
 *
 * @array: array from which to print
 * @start: lower bound (inclusive)
 * @stop: upper bound (exclusive)
 */
static void _print_slice(int *array, size_t start, size_t stop)
{
	printf("Searching in array: ");
	while (start < stop)
	{
		printf("%d", array[start++]);
		if (start < stop)
			printf(", ");
	}
	printf("\n");
}

/**
 * _advanced_binary - search for a value in a sorted array
 *
 * @array: array in which to search
 * @start: start bound (inclusive)
 * @stop: stop bound (exclusive)
 * @value: value for which to search
 *
 * Return: If array is NULL or value is not in array, return -1.
 * Otherwise, returh the lowest index at which value is located.
 */
static int _advanced_binary(int *array, size_t start, size_t stop, int value)
{
	size_t index = (start + stop - 1) / 2;

	if (start >= stop)
		return (-1);
	_print_slice(array, start, stop);
	if (array[index] < value)
		return (_advanced_binary(array, index + 1, stop, value));
	if (array[index] > value)
		return (_advanced_binary(array, start, index, value));
	if (index && array[index - 1] == value)
		return (_advanced_binary(array, start, index, value));
	return (index);
}

/**
 * advanced_binary - search for a value in a sorted array of integers
 * @array: the array of values
 * @size: the number of values
 * @value: the value to locate
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, returh the first index where value is located.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array && size)
		return (_advanced_binary(array, 0, size, value));
	return (-1);
}
