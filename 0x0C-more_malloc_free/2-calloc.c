#include <stdlib.h>
#include <string.h>

/**
 * _calloc - Allocates memory for an array using malloc
 * @size: positive number
 * @nmemb: positive number
 * Return: NULL on fail or if size or nmemb = 0 or pointer to the allocated mem
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * sizeof(int));

	if (p == 0)
		return (NULL);

	memset(p, 0, nmemb * sizeof(int));

	return (p);
}
