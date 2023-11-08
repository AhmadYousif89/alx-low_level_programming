#include <stdio.h>

/**
 * int_index -  Search for an integer using a pointer to function
 * @array: pointer to the array
 * @size: size of the array
 * @cmp: pointer to function
 * Return: Nothing.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && size && cmp)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
				return (i);
		}
	}

	return (-1);
}
