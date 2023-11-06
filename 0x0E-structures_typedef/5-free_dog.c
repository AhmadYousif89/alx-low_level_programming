#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dog.h"

/**
 * free_dog - Free the dogs
 * @d: pointer to the dog struct
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
