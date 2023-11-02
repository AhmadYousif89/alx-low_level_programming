#include <stdlib.h>
#include <string.h>

/**
 * array_range - Allocates memory for an array of numbers | malloc
 * @min: minimum number to start
 * @max: maximum number to end
 * Return: NULL on fail or if min > max or pointer to the allocated array
 */
int *array_range(int min, int max)
{
	int i, length;
	int *arr;

	if (min > max)
		return (NULL);

	for (i = min; i <= max; i++)
		;
	length = i;

	arr = malloc(length * sizeof(int));

	if (arr == NULL)
		return (NULL);

	i = 0;
	for (i = min; i < length; i++)
		arr[i] = i;

	return (arr);
}
