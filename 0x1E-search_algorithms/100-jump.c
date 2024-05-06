#include "search_algos.h"
#define min(a, b) (((a) < (b)) ? (a) : (b))

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
	int step = sqrt(size);
	int i, prev = 0;
	int curr = step;

	if (array == NULL || size == 0)
		return (-1);

	printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
	while (curr < (int)size && array[curr] < value)
	{
		printf("Value checked array[%d] = [%d]\n", curr, array[curr]);
		prev = curr;
		curr += step;
	}

	printf("Value found between indexes [%d] and [%d]\n", prev, curr);

	for (i = prev; i <= curr && i < (int)size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
