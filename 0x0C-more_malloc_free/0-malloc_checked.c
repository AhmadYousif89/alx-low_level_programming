#include <stdlib.h>

/**
 * malloc_checked - Allocate memory using malloc
 * @b: number
 * Return: on fails return (98) or Pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	unsigned int *p;

	p = malloc(b * sizeof(int));

	if (p == NULL)
		exit(98);

	return (p);
}
