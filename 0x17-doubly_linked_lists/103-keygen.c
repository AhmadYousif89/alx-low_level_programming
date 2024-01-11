/* THIS IS NOT MY CODE */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
#define KEY_LENGTH 6

/**
 * main - generate a key depending on a username for crackme5
 * @argc: number of arguments passed
 * @argv: arguments passed to main
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	unsigned int i, b;
	size_t len, add;
	char key[KEY_LENGTH + 1] = "      "; /* +1 for null char */

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	len = strlen(argv[1]);
	key[0] = ALPHABET[(len ^ 59) & 63];
	for (i = 0, add = 0; i < len; i++)
		add += argv[1][i];
	key[1] = ALPHABET[(add ^ 79) & 63];
	for (i = 0, b = 1; i < len; i++)
		b *= argv[1][i];
	key[2] = ALPHABET[(b ^ 85) & 63];
	for (b = argv[1][0], i = 0; i < len; i++)
		if ((char)b <= argv[1][i])
			b = argv[1][i];
	srand(b ^ 14);
	key[3] = ALPHABET[rand() & 63];
	for (b = 0, i = 0; i < len; i++)
		b += argv[1][i] * argv[1][i];
	key[4] = ALPHABET[(b ^ 239) & 63];
	for (b = 0, i = 0; (char)i < argv[1][0]; i++)
		b = rand();
	key[5] = ALPHABET[(b ^ 229) & 63];
	printf("%s\n", key);
	return (0);
}
