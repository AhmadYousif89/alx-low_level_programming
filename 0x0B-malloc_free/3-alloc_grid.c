#include <stdlib.h>

/**
 * alloc_grid - Allocate memory for 2 dimensional array
 * @width: the grid width
 * @height: the grid height
 * Return:
 * NULL if width or height is 0 or negative
 * Pointer to a newly allocated 2 dimensional array
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i;

	if (width <= 0 || height <= 0)
		return (NULL);

	/* Allocate memory for the rows */
	grid = (int **)malloc(sizeof(int *) * height);

	if (grid == NULL) /* Memory allocation failed */
		return (NULL);

	/* Allocate memory for the columns */
	for (i = 0; i < height; i++)
	{
		grid[i] = (int *)malloc(sizeof(int) * width); /* Init with (0) */
	}

	return (grid);
}
