/* THIS IS NOT MY CODE */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
#define KEY_LENGTH 6
#define MAX_INDEX 63

/**
 * generate_key - Generate a key based on the given username
 * @username: input username
 * @key: output key
 */
void generate_key(const char *username, char *key)
{
	size_t len, add;
	unsigned int i, acc;

	len = strlen(username);
	key[0] = ALPHABET[(len ^ 59) & MAX_INDEX];
	for (i = 0, add = 0; i < len; i++)
		add += username[i];

	key[1] = ALPHABET[(add ^ 79) & MAX_INDEX];
	for (i = 0, acc = 1; i < len; i++)
		acc *= username[i];

	key[2] = ALPHABET[(acc ^ 85) & MAX_INDEX];
	for (acc = username[0], i = 0; i < len; i++)
		if ((char)acc <= username[i])
			acc = username[i];

	srand(acc ^ 14);
	key[3] = ALPHABET[rand() & MAX_INDEX];
	for (acc = 0, i = 0; i < len; i++)
		acc += username[i] * username[i];

	key[4] = ALPHABET[(acc ^ 239) & MAX_INDEX];
	for (acc = 0, i = 0; (char)i < username[0]; i++)
		acc = rand();

	key[5] = ALPHABET[(acc ^ 229) & MAX_INDEX];
}

/**
 * main - generate a key depending on a username for crackme5
 * @argc: number of arguments passed
 * @argv: arguments passed to main
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	char key[KEY_LENGTH + 1] = "      "; /* +1 for null char */

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}

	generate_key(argv[1], key);
	printf("%s\n", key);
	return (0);
}
