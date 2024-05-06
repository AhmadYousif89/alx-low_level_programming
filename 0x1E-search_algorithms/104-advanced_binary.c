#include "search_algos.h"

/**
 * advanced_binary_recursive - searches for a value recursively.
 * @array: pointer to the array
 * @left: left index of the array
 * @right: right index of the array
 * @value: the value to search for
 *
 * Return: the index where value is located, or
 *         -1 if array is null or value not found
 */
int advanced_binary_recursive(int *array, int left, int right, int value)
{
	int i, idx;

	if (array == NULL || left > right)
		return (-1);

	idx = left + (right - left) / 2;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
		printf("%d%s", array[i], i != right ? ", " : "\n");

	/* Found the value at first occurrence */
	if (array[idx] == value && (idx == left || array[idx - 1] != value))
		return (idx);

	if (array[idx] >= value)
		return (advanced_binary_recursive(array, left, idx, value));

	return (advanced_binary_recursive(array, idx + 1, right, value));
}

/**
 * advanced_binary - searches for a value in an array of integers.
 * @array: pointer to the array
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: the index where value is located, or
 *         -1 if array is null or value not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
