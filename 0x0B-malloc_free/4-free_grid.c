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
		if (grid[i] == NULL)
		{ /* Free previously allocated memory before returning NULL */
			while (i >= 0)
			{
				free(grid[i]);
				i--;
			}
			free(grid);
		}
	}
}
