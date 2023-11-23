#include "main.h"

/**
 * get_endianness - Check endianness of the system
 * Return: 1 if little endian or 0 if big endian
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *check_endian = (char *)&num;

	/* If the first byte is non-zero, it's little endian */
	return (*check_endian == 1);
}
