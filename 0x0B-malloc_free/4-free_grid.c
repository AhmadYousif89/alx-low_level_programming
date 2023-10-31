#include <stdlib.h>

/**
 * free_grid - Free a 2 dimensional grid
 * @grid: pointer to the grid
 * @height: the grid height
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
