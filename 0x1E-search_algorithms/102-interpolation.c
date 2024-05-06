#include "search_algos.h"

/**
 * interpolation_search - searches for a value in an array of integers.
 * @array: pointer to the array
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: the index where value is located, or
 *         -1 if array is null or value not found
 */
int interpolation_search(int *array, size_t size, int value)
{
	int low = 0;
	int high = size - 1;

	if (array == NULL || size == 0)
		return (-1);

	while (low <= high && value >= array[low] && value <= array[high])
	{
		size_t pos = low + (((double)(high - low) / (array[high] - array[low])) *
							(value - array[low]));

		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return (pos);
		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}

	printf("Value checked array[%u] is out of range\n", high);
	return (-1);
}
