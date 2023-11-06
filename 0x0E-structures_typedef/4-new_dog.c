#include <stdlib.h>
#include <string.h>
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
	struct dog *_dog;

	_dog = malloc(sizeof(struct dog));

	if (_dog == NULL)
		return (NULL);
	/* Allocate and copy name */
	_dog->name = malloc(sizeof(strlen(name)) + 1);
	strcpy(_dog->name, name);
	if (_dog->name == NULL)
	{
		free(_dog);
		return (NULL);
	}
	/* Allocate and copy owner */
	_dog->owner = malloc(sizeof(_dog->owner) + 1);
	if (_dog->owner == NULL)
	{
		free(_dog->name);
		free(_dog);
		return (NULL);
	}
	strcpy(_dog->owner, owner);
	_dog->age = age;

	return (_dog);
}
