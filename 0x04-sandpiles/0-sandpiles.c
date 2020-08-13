#include <stdbool.h>
#include <stdio.h>

#include "sandpiles.h"


/**
 * print_grid - print a sandpile
 * @grid: the sandpile to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}


/**
 * is_stable - check if a sandpile is stable
 * @grid: the sanpile to evaluate
 * Return: true if grid is stable, otherwise false
 */
static bool is_stable(int grid[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if (grid[i][j] > 3)
				return (false);
		}
	}
	return (true);
}


/**
 * add_sandpile - add two sandpiles
 * @grid1: the first sandpile (destination)
 * @grid2: the second sandpile
 * Return: true if grid1 is stable, otherwise false
 */
static bool add_sandpile(int grid1[3][3], int grid2[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	return (is_stable(grid1));
}


/**
 * topple_sandpile - topple a sandpile
 * @grid: the sandpile to topple
 * Return: true if grid is stable, otherwise false
 */
static bool topple_sandpile(int grid[3][3])
{
	size_t i, j;
	int temp[3][3] = {{0}};

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i > 0)
					temp[i - 1][j] += 1;
				if (i < 2)
					temp[i + 1][j] += 1;
				if (j > 0)
					temp[i][j - 1] += 1;
				if (j < 2)
					temp[i][j + 1] += 1;
			}
		}
	}
	return (add_sandpile(grid, temp));
}


/**
 * sandpiles_sum - compute the sum of two sandpiles
 * @grid1: the first sandpile (destination)
 * @grid2: the second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	if (!add_sandpile(grid1, grid2))
	{
		do {
			puts("=");
			print_grid(grid1);
		} while (!topple_sandpile(grid1));
	}
}
