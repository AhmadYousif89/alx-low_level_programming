#include "search_algos.h"

/**
 * jump_search - searches for a value in an array of integers.
 * @array: pointer to the array
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: the index where value is located, or
 *         -1 if array is null or value not found
 */
int jump_search(int *array, size_t size, int value)
{

	size_t i, step = sqrt(size);
	size_t current = step;
	size_t prev = 0;

	if (array == NULL || size == 0)
		return (-1);

	while (current < size && array[current] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", current, array[current]);
		prev = current;
		current += step;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev, current);

	for (i = prev; i < size && i <= current; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
