#include "search_algos.h"

/**
 * _binary_search - searches for a value in an array of integers.
 * @array: pointer to the array
 * @low: tThe starting index of the left sub-array
 * @high: tThe starting index of the right sub-array
 * @value: the value to search for
 *
 * Return: the index where value is located, or
 *         -1 if array is null or value not found
 */
int _binary_search(int *array, int low, int high, int value)
{
	int idx, i;

	while (low <= high)
	{
		idx = low + (high - low) / 2;

		printf("Searching in array: ");
		for (i = low; i <= high; i++)
			printf("%d%s", array[i], i != high ? ", " : "\n");

		if (array[idx] == value)
			return (idx);
		if (array[idx] < value)
			low = idx + 1;
		else
			high = idx - 1;
	}
	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array of integers
 *                      using the Exponential search algorithm
 *
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The first index where the value is located, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	int i;
	int high, low;

	if (array == NULL || size == 0)
		return (-1);

	if (array[0] == value)
		return (0);

	for (i = 1; i < (int)size && array[i] <= value; i = i * 2)
		printf("Value checked array[%d] = [%d]\n", i, array[i]);

	high = (i < (int)size) ? i : (int)size - 1, low = i / 2;

	printf("Value found between indexes [%d] and [%d]\n", low, high);

	return (_binary_search(array, low, high, value));
}
