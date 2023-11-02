#include <stdlib.h>

/**
 * malloc_checked - Allocate memory using malloc
 * @b: number
 * Return: on fails exit(98) or Pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (p == NULL)
		exit(98);

	return (p);
}
