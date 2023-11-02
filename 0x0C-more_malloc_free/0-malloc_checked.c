#include <stdlib.h>

/**
 * malloc_checked - Allocate memory using malloc
 * @b: number
 * Return: on fails exit(98) or Pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b * sizeof(unsigned int));

	if (p == NULL)
		exit(98);

	return (p);
}
