#ifndef DOG_STRUCT_H
#define DOG_STRUCT_H

/**
 * struct dog - Personal dog struct
 * @owner: the owner of the dog -> string
 * @name: the dog name -> string
 * @age: the dog age -> float
 */
struct dog
{
	char *owner;
	char *name;
	float age;
};

#endif
