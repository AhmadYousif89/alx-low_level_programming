#include <stdio.h>

/**
 * array_iterator - Print a array elements using a pointer to function
 * @array: pointer to the array
 * @size: size of the array
 * @action: pointer to the printing function
 * Return: Nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (!array || !action)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
