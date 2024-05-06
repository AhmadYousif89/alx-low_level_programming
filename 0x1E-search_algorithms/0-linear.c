#include "search_algos.h"

/**
 * linear_search - searches for a value in an array of integers.
 * @array: pointer to the array
 * @size: size of the array
 * @value: value to be searched
 *
 * Return: the first index where value is located, or
 *          -1 if array is null or value to found
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return ((int)i);
	}

	return (-1);
}
