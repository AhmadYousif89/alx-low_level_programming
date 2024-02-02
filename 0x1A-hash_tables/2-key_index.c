#include "hash_tables.h"

/**
 * key_index - Get the index of a key in the hash table.
 * @key: the key used in the searching process
 * @size: the size of the hash table's array
 * Return: the index at which the key/value pair is stored
 */
__uint64_t key_index(const unsigned char *key, __uint64_t size)
{
	if (key == NULL || size == 0)
		return (0);
	return (hash_djb2(key) % size);
}
