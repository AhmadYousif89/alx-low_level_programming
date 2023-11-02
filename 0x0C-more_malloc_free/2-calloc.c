#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array using malloc
 * @size: positive number
 * @nmemb: positive number
 * Return: NULL on fail or if size or nmemb = 0 or pointer to the allocated mem
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned alloc_size = 0;
	void *p;
	char *s;

	if (nmemb == 0 || size == 0)
		return (NULL);

	alloc_size = nmemb * sizeof(int);
	p = malloc(alloc_size);

	if (p == NULL)
		return (NULL);

	s = p;
	while (alloc_size--)
		*s++ = 0;

	return (p);
}
