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
void menger_fill(char **lines, size_t x_i, size_t x_o, size_t y_i, size_t y_o)
{
	int p = (x_o - x_i) / 3;

	if (p)
	{
		menger_fill(lines, x_i, x_i + p, y_i, y_i + p);
		menger_fill(lines, x_i, x_i + p, y_i + p, y_o - p);
		menger_fill(lines, x_i, x_i + p, y_o - p, y_o);

		menger_fill(lines, x_i + p, x_i + p * 2, y_i, y_i + p);
		menger_fill(lines, x_i + p, x_i + p * 2, y_o - p, y_o);

		menger_fill(lines, x_o - p, x_o, y_i, y_i + p);
		menger_fill(lines, x_o - p, x_o, y_i + p, y_o - p);
		menger_fill(lines, x_o - p, x_o, y_o - p, y_o);
	}
	else
	{
		lines[x_i][y_i] = FILL_CHARACTER;
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
