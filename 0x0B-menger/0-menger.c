#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menger.h"

/**
 * menger_fill - recursively fill a 2-dimensional menger sponge
 *
 * @grid: new menger sponge
 * @row_0: starting x coordinate
 * @row_1: ending x coordinate
 * @col_0: starting y coordinate
 * @col_1: ending y coordinate
 */
static void menger_fill(
	char **grid, size_t row_0, size_t row_1, size_t col_0, size_t col_1)
{
	int p = (row_1 - row_0) / 3;

	if (p)
	{
		menger_fill(grid, row_0, row_0 + p, col_0, col_0 + p);
		menger_fill(grid, row_1 - p, row_1, col_0, col_0 + p);

		menger_fill(grid, row_0, row_0 + p, col_1 - p, col_1);
		menger_fill(grid, row_1 - p, row_1, col_1 - p, col_1);

		menger_fill(grid, row_0, row_0 + p, col_0 + p, col_1 - p);
		menger_fill(grid, row_1 - p, row_1, col_0 + p, col_1 - p);

		menger_fill(grid, row_0 + p, row_0 + 2 * p, col_0, col_0 + p);
		menger_fill(grid, row_0 + p, row_0 + 2 * p, col_1 - p, col_1);
	}
	else
	{
		grid[row_0][col_0] = FILL_CHARACTER;
	}
}

/**
 * menger_free - free a 2-dimensional menger sponge
 *
 * @grid: dynamically-allocated menger sponge
 * @size: length of each side
 */
static void menger_free(char **grid, size_t size)
{
	size_t index = 0;

	while (index < size)
		free(grid[index++]);
	free(grid);
}

/**
 * menger_new - allocate and initialize a 2-dimensional menger sponge
 *
 * @size: length of each side
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to a new menger sponge.
 */
static char **menger_new(size_t size)
{
	size_t index = 0;
	char **grid = malloc(sizeof(*grid) * size);

	if (!grid)
		return (NULL);

	while (index < size)
	{
		grid[index] = malloc(sizeof(**grid) * size);

		if (!grid[index])
		{
			menger_free(grid, index);
			return (NULL);
		}

		memset(grid[index++], BLANK_CHARACTER, size);
	}
	return (grid);
}

/**
 * menger_print - print a 2-dimensional menger sponge
 *
 * @grid: filled menger sponge
 * @size: length of each side
 */
static void menger_print(char **grid, size_t size)
{
	size_t index = 0;

	while (index < size)
	{
		fwrite(grid[index++], sizeof(**grid), size, stdout);
		fputc('\n', stdout);
	}
}

/**
 * menger - construct and print a 2-dimensional menger sponge
 *
 * @level: fractal depth
 */
void menger(int level)
{
	size_t size = 0;
	char **grid = NULL;

	if (level < 0)
		return;

	size = pow(3, level);
	grid = menger_new(size);
	if (!grid)
		return;

	menger_fill(grid, 0, size, 0, size);
	menger_print(grid, size);
	menger_free(grid, size);
}
