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
	size_t i, jump, step;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);
	for (i = 0; i < size; i += step)
	{
		if (array[i] >= value)
		{
			jump = i - step;
			printf("Value found between indexes [%lu] and [%lu]\n", jump, i);
			for (; jump <= i && jump < size; jump++)
			{
				printf("Value checked array[%lu] = [%d]\n", jump, array[jump]);
				if (array[jump] == value)
					return (jump);
			}
			break;
		}
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
	}

	jump = i - step;
	printf("Value found between indexes [%lu] and [%lu]\n", jump, i);
	for (; jump < size; jump++)
	{
		printf("Value checked array[%lu] = [%d]\n", jump, array[jump]);
		if (array[jump] == value)
			return (jump);
	}

	return (-1);
}
