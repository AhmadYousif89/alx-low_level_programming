#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generate random password.
 * Return: 0.
 */

int main(void)
{
	int i = 0;
	int c, random;
	int ascii = 2772;
	char password[50]; /* Password length */

	srand(time(NULL));
	while (ascii > 127)
	{
		random = rand() % 127;
		password[i] = random;
		ascii -= random;
		i++;
	}

	if (ascii > 0)
		password[i] = ascii;
	else
		i--;

	for (c = 0; c <= i; c++)
	{
		printf("%c", password[c]);
	}

	return (0);
}