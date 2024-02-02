#include "hash_tables.h"

/**
 * hash_table_get - Retrieve a value associated with a key.
 * @ht: pointer to the hash table struct
 * @key: the key
 * Return: the value associated with the element,
 *			or NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *current;
	__uint64_t idx, size;

	if (ht == NULL || key == NULL)
		return (NULL);

	size = ht->size;
	idx = key_index(key, size);
	current = ht->array[idx];

	while (current)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}

	return (NULL);
}
