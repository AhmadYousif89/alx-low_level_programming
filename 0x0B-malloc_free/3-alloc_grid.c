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
	int **arr;
	int i;

	if (width == 0 || height == 0)
		return (NULL);

	/* Allocate memory for the rows */
	arr = (int **)malloc(sizeof(int) * height);

	if (arr == NULL)
		return (NULL);

	/* Allocate memory for the columns */
	for (i = 0; i < height; i++)
	{
		arr[i] = (int *)malloc(sizeof(int) * width);
		if (arr[i] == NULL)
		{
			while (i >= 0)
			{
				free(arr[i]);
				i--;
			}
			free(arr);
			return (NULL);
		}
	}

	return (arr);
}
