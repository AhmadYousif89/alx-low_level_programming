#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - Print a dog structure
 * @d: pointer to the dog struct
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		exit(EXIT_FAILURE);

	printf("Name: %s\n", (d->name == NULL ? "(nil)" : d->name));
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", (d->owner == NULL ? "(nil)" : d->owner));
}
