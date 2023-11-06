#include "dog.h"

/**
 * init_dog - Create a dog structure
 * @d: pointer to the dog struct
 * @name: the dog name -> string
 * @age: the dog age -> float
 * @owner: the owner of the dog -> string
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->owner = owner;
	d->age = age;
}
