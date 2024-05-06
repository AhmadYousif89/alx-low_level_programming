#include "search_algos.h"

/**
 * binary_search_recursive - searches for a value recursively.
 * @array: pointer to the array
 * @left: left index of the array
 * @right: right index of the array
 * @value: the value to search for
 *
 * Return: the index where value is located, or
 *         -1 if array is null or value not found
 */
int binary_search_recursive(int *array, int left, int right, int value)
{
	int i, mid;

	if (array == NULL || left > right)
		return (-1);

	mid = left + (right - left) / 2;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
		printf("%d%s", array[i], i != right ? ", " : "\n");

	if (array[mid] == value)
		return (mid);
	else if (array[mid] > value)
		return (binary_search_recursive(array, left, mid - 1, value));
	else
		return (binary_search_recursive(array, mid + 1, right, value));
}

/**
 * binary_search - searches for a value in an array of integers.
 * @array: pointer to the array
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: the index where value is located, or
 *         -1 if array is null or value not found
 */
int binary_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search_recursive(array, 0, size - 1, value));
}
