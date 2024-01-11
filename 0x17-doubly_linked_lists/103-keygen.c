/* THIS IS NOT MY CODE */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
#define KEY_LENGTH 6

/**
 * generate_key - Generate a key based on the given username
 * @username: input username
 * @key: output key
 */
void generate_key(const char *username, char *key)
{
	size_t len = strlen(username);

	key[0] = ALPHABET[(len ^ 59) & 63];

	size_t add = 0;
	for (size_t i = 0; i < len; i++)
		add += username[i];
	key[1] = ALPHABET[(add ^ 79) & 63];

	unsigned int b = 1;
	for (size_t i = 0; i < len; i++)
		b *= username[i];
	key[2] = ALPHABET[(b ^ 85) & 63];

	b = (unsigned int)username[0];
	for (size_t i = 0; i < len; i++)
		if ((char)b <= username[i])
			b = username[i];

	srand(b ^ 14);
	key[3] = ALPHABET[rand() & 63];

	unsigned int sum_squares = 0;
	for (size_t i = 0; i < len; i++)
		sum_squares += username[i] * username[i];
	key[4] = ALPHABET[(sum_squares ^ 239) & 63];

	b = 0;
	for (size_t i = 0; (char)i < username[0]; i++)
		b = rand();
	key[5] = ALPHABET[(b ^ 229) & 63];
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Argument list
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	char key[KEY_LENGTH + 1]; /* +1 for null terminator */

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}

	generate_key(argv[1], key);

	printf("%s\n", key);
	return (0);
}
