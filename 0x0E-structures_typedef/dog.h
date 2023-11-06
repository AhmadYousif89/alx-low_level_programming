#ifndef DOG_STRUCT_H
#define DOG_STRUCT_H

typedef struct dog dog_t;
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

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif
