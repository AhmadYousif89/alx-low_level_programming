#include "hash_tables.h"

/**
 * hash_table_create - Create a new Hash table.
 * @size: the size of the hash table's array
 * Return: pointer to the newly created hash table or NULL otherwise.
 */
hash_table_t *hash_table_create(__uint64_t size)
{
	__uint64_t i;
	hash_table_t *new_ht;

	new_ht = malloc(sizeof(hash_table_t));
	if (new_ht == NULL)
		return (NULL);

	new_ht->size = size;
	new_ht->array = malloc(sizeof(hash_node_t *) * size);
	if (new_ht->array == NULL)
	{
		free(new_ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		new_ht->array[i] = NULL;

	return (new_ht);
}
