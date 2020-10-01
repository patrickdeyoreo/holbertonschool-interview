#include "slide_line.h"

/**
 * slide_left - slide a line to the left
 * @line: pointer to the line
 * @size: size of the line
 *
 * Return: Always return (1).
 */
static int slide_left(int *line, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	int prev = 0;

	while (j < size)
	{
		if (line[j])
		{
			if (prev == 0)
			{
				prev = line[j];
			}
			else if (prev == line[j])
			{
				line[i++] = line[j] << 1;
				prev = 0;
			}
			else
			{
				line[i++] = prev;
				prev = line[j];
			}
		}
		j += 1;
	}

	if (prev)
		line[i++] = prev;

	while (i < size)
		line[i++] = 0;

	return (1);
}

/**
 * slide_right - slide a line to the right
 * @line: pointer to the line
 * @size: size of the line
 *
 * Return: Always return (1).
 */
static int slide_right(int *line, size_t size)
{
	size_t i = size - 1;
	size_t j = size - 1;
	int prev = 0;

	while (j < size)
	{
		if (line[j])
		{
			if (prev == 0)
			{
				prev = line[j];
			}
			else if (prev == line[j])
			{
				line[i--] = line[j] << 1;
				prev = 0;
			}
			else
			{
				line[i--] = prev;
				prev = line[j];
			}
		}
		j -= 1;
	}

	if (prev)
		line[i--] = prev;

	while (i < size)
		line[i--] = 0;

	return (1);
}

/**
 * slide_line - slide a line
 * @line: pointer to the line
 * @size: size of the line
 * @direction: direction to slide
 *
 * Return: If line is NULL or direction is invalid, return 0.
 * Otherwise, return 1.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line)
	{
		if (direction == SLIDE_LEFT)
			return (slide_left(line, size));
		if (direction == SLIDE_RIGHT)
			return (slide_right(line, size));
	}
	return (0);
}
