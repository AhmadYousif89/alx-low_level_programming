#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Print a dog structure
 * @d: pointer to the dog struct
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
}
