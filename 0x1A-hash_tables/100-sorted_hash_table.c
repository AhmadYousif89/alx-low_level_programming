#include "hash_tables.h"

/**
 * shash_table_create - Create the hash table.
 * @size: the size to be allocated for the hashtable
 * Return: pointer to the created hashtable, or NULL.
 */
shash_table_t *shash_table_create(__uint64_t size)
{
	shash_table_t *new_ht;
	__uint64_t i;

	new_ht = malloc(sizeof(shash_table_t));
	if (new_ht == NULL)
		return (NULL);

	new_ht->size = size;
	new_ht->shead = NULL;
	new_ht->stail = NULL;
	new_ht->array = malloc(sizeof(shash_node_t *) * size);
	if (new_ht->array == NULL)
	{
		free(new_ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		new_ht->array[i] = NULL;

	return (new_ht);
}

/**
 * shash_node_create - Create the hash table.
 * @key: the key to retrive the index position
 * @value: the value to be inserted/updated
 * Return: pointer to the new node, NULL otherwise.
 */
shash_node_t *shash_node_create(const char *key, const char *value)
{
	shash_node_t *node;

	if (key == NULL || value == NULL)
		return (NULL);

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (NULL);
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}
	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}
	node->next = NULL;
	node->snext = NULL;
	node->sprev = NULL;

	return (node);
}

/**
 * sort_hash_table - Sort the hash table.
 * @ht: pointer to the hashtable.
 * @node: pointer to head node.
 */
void sort_hash_table(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *current;
	char *key;

	if (ht == NULL || ht->array == NULL || node == NULL)
		return;
	/* Case of empty HT both head and tail should point to the new node */
	if (ht->shead == NULL && ht->stail == NULL)
	{
		ht->shead = ht->stail = node;
		return;
	}
	/* Sorting the Hashtable */
	current = ht->shead;
	while (current)
	{
		key = current->key;
		/* Case node->key has lower ascii value than the current->key */
		/* Then insert before the current node */
		if (strcmp(node->key, key) < 0)
		{
			node->snext = current;
			node->sprev = current->sprev;
			current->sprev = node;
			/* If the node previous to the current node exist */
			if (node->sprev)
				node->sprev->snext = node;
			else
				ht->shead = node;
			return;
		}

		current = current->snext;
	}
	/* Insert node at the end */
	node->sprev = ht->stail;
	ht->stail->snext = node;
	ht->stail = node;
}

/**
 * shash_table_set - Add new element to the hash table.
 * @ht: pointer to the hashtable struct
 * @key: the key to retrive the index position
 * @value: the value to be inserted/updated
 * Return: 1 on success 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node, *current;
	__uint64_t idx, size;

	if (ht == NULL || ht->array == NULL || key == NULL || value == NULL)
		return (0);
	size = ht->size;
	idx = key_index((const unsigned char *)key, size);
	current = ht->array[idx];

	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (current->value == NULL)
				return (0);
			return (1);
		}
		current = current->next;
	}

	node = shash_node_create(key, value);
	if (node == NULL)
		return (0);
	node->next = ht->array[idx];
	ht->array[idx] = node;
	sort_hash_table(ht, node);
	return (1);
}

/**
 * shash_table_get - Retrieve a value associated with a key.
 * @ht: pointer to the hashtable struct
 * @key: the key to retrive the index position
 * Return: the value associated with the element,
 *			or NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *current;
	__uint64_t idx;

	if (ht == NULL || ht->array == NULL || key == NULL)
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	current = ht->array[idx];

	while (current)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Print the hash table content.
 * @ht: pointer to the hashtable struct
 */
void shash_table_print(const shash_table_t *ht)
{
	int printed = 0;
	shash_node_t *current;
	char *key, *value;

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");

	current = ht->shead;
	while (current)
	{
		key = current->key;
		value = current->value;
		if (printed)
			printf(", ");
		printf("'%s': '%s'", key, value);
		printed = 1;
		current = current->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - Print the hash table content in reverse.
 * @ht: pointer to the hashtable struct
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	int printed = 0;
	shash_node_t *current;
	char *key, *value;

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");

	current = ht->stail;
	while (current)
	{
		key = current->key;
		value = current->value;
		if (printed)
			printf(", ");
		printf("'%s': '%s'", key, value);
		printed = 1;
		current = current->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - Delete the hash table and its content.
 * @ht: pointer to the hashtable struct
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current, *temp;
	__uint64_t i;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;

	for (i = 0; i < ht->size; i++)
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
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
