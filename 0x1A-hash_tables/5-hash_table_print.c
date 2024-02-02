#include "hash_tables.h"

/**
 * hash_table_print - Print the hash table.
 * @ht: pointer to the hash table struct
 */
void hash_table_print(const hash_table_t *ht)
{
	int printed = 0;
	__uint64_t i, size;
	hash_node_t *current;
	char *key, *value;

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");
	size = ht->size;
	for (i = 0; i < size; i++)
	{
		current = ht->array[i];
		while (current)
		{
			key = current->key;
			value = current->value;
			if (printed)
				printf(", ");
			printf("'%s': '%s'", key, value);
			printed = 1;
			current = current->next;
		}
	}
	printf("}\n");
}
