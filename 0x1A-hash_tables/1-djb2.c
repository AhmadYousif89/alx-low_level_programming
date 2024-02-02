#include "hash_tables.h"

/**
 * hash_djb2 - The djb2 hashing algorithm
 * @str: string used to generate hash value.
 * Return: hash value.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	__uint64_t hash;
	int c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	/* hashing... "cisfun" */
	/* 'c' => (172192 + 5381) + 99 == 177,672 */
	/* 'i' => (5685504 + 177,672) + 105 == 5,863,281 */
	/* 's' => (187624992 + 5,863,281) + 115 == 193,488,388 */
	/* 'f' => (6,191,628,416 + 193,488,388) + 102 == 6,385,116,906 */
	/* 'u' => (204,323,740,992 + 6,385,116,906) + 117 == 210,708,858,015 */
	/* 'n' => (6,742,683,456,480 + 210,708,858,015) + 110 == 6,953,392,314,605 */
	return (hash); /* hash == 6,953,392,314,605 */
}
