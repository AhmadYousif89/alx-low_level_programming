#include <stdlib.h>

/**
 * create_array - Create and initialize an array of chars with a specific char
 * @size: positive number
 * @c: char
 * Return: NULL if size = 0 or on fails, otherwise a pointer to the array
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *arr;

	if (size == 0)
		return (NULL);

	arr = (char *)malloc(sizeof(char) * size);

	for (i = 0; i < size; i++)
	{
		arr[i] = c;
	}

	return (arr);
}
