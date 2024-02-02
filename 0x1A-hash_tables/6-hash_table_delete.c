#include "hash_tables.h"

/**
 * hash_table_delete - Delete a hash table and its content.
 * @ht: pointer to the hash table struct
 */
void hash_table_delete(hash_table_t *ht)
{
	__uint64_t i, size;
	hash_node_t *current, *temp;

	if (ht == NULL || ht->array == NULL)
		return;

	size = ht->size;
	for (i = 0; i < size; i++)
	{
		current = ht->array[i];
		while (current)
		{
			temp = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current = temp;
		}
	}

	free(ht->array);
	free(ht);
}
