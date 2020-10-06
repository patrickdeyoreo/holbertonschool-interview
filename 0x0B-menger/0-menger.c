#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menger.h"

/**
 * allocate_lines - allocate and fill a 2-dimensional square grid of characters
 * @c: fill character
 * @n: length of each side
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to a dynamically allocated array.
 */
char **allocate_lines(char c, size_t n)
{
	size_t index = 0;
	char **lines = malloc(sizeof(*lines) * n);

	if (!lines)
		return (NULL);

	while (index < n)
	{
		lines[index] = malloc(sizeof(**lines) * n);

		if (!lines[index])
		{
			while (index--)
			{
				free(lines[index]);
			}
			free(lines);
			return (NULL);
		}

		memset(lines[index++], c, n);
	}
	return (lines);
}

/**
 * menger_fill - recursively fill a 2-dimensional menger sponge
 *
 * @lines: empty menger sponge
 * @x_i: starting x coordinate
 * @x_o: ending x coordinate
 * @y_i: starting y coordinate
 * @y_o: ending y coordinate
 */
void menger_fill(char **lines, size_t x_0, size_t x_1, size_t y_0, size_t y_1)
{
	int p = (x_1 - x_0) / 3;

	if (p)
	{
		menger_fill(lines, x_0, x_0 + p, y_0, y_0 + p);
		menger_fill(lines, x_1 - p, x_1, y_0, y_0 + p);

		menger_fill(lines, x_0, x_0 + p, y_1 - p, y_1);
		menger_fill(lines, x_1 - p, x_1, y_1 - p, y_1);

		menger_fill(lines, x_0, x_0 + p, y_0 + p, y_1 - p);
		menger_fill(lines, x_1 - p, x_1, y_0 + p, y_1 - p);

		menger_fill(lines, x_0 + p, x_0 + 2 * p, y_0, y_0 + p);
		menger_fill(lines, x_0 + p, x_0 + 2 * p, y_1 - p, y_1);
	}
	else
	{
		lines[x_0][y_0] = FILL_CHARACTER;
	}
}


/**
 * menger_print - print 2-dimensional menger sponge
 *
 * @lines: filled menger sponge
 * @n: length of each side
 */
void menger_print(char **lines, size_t n)
{
	while (n--)
		fwrite(*lines++, sizeof(**lines), n, stdout);
}

/**
 * menger - print a 2-dimensional menger sponge
 *
 * @level: fractal depth of the sponge
 */
void menger(int level)
{
	size_t n = 0, i = 0;
	char **lines = NULL;

	if (level < 0)
		return;

	n = pow(3, level);
	lines = allocate_lines(' ', n);
	if (!lines)
		return;

	menger_fill(lines, 0, n, 0, n);

	for (i = 0; i < n; i += 1)
	{
		fwrite(lines[i], sizeof(**lines), n, stdout);
		fputc('\n', stdout);
		free(lines[i]);
	}
	free(lines);
}
