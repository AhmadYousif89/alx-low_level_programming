#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array using malloc
 * @size: positive number
 * @nmemb: positive number
 * Return: NULL on fail or if size or nmemb = 0 or pointer to the allocated mem
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned i;
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);

	if (p == NULL)
		return (NULL);

	for (i = 0; i < nmemb; i++)
	{
		p[i] = 0;
	}

	return (p);
}
