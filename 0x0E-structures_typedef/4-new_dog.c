#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - Init a dog structure using a pointer
 * @owner: the owner of the dog -> string
 * @name: the dog name -> string
 * @age: the dog age -> float
 * Return: pointer to the dog struct
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	struct dog *p_dog;

	p_dog = malloc(sizeof(struct dog));

	if (p_dog == NULL)
		return (NULL);

	p_dog->name = name;
	p_dog->age = age;
	p_dog->owner = owner;

	return (p_dog);
}
