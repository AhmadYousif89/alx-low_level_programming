#include "hash_tables.h"

/**
 * hash_table_set - Add new element to the hash table.
 * @ht: pointer to the hash table struct
 * @key: the key
 * @value: the value
 * Return: 1 on success 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *current_node, *new_node;
	__uint64_t idx = 0, size;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);
	size = ht->size;
	idx = key_index((const unsigned char *)key, size);
	/* Try to set the new value at an existing location */
	current_node = ht->array[idx];
	while (current_node)
	{
		if (strcmp(current_node->key, key) == 0)
		{
			free(current_node->value);
			current_node->value = strdup(value);
			if (current_node->value == NULL)
				return (0);
			return (1);
		}
		current_node = current_node->next;
	}
	/* Case of empty array: Set the value inside a new node at the beginning */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key); /* Add the key */
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = strdup(value); /* Add the value */
	if (new_node->value == NULL)
	{
		free(new_node->key), free(new_node);
		return (0);
	}
	new_node->next = ht->array[idx]; /* place the node at the beginning */
	ht->array[idx] = new_node;
	return (1);
}
