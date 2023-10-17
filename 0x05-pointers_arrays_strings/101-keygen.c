#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generate random password.
 * Return: 0.
 */

int main(void)
{
	int j, random;
	int i = 0, ascii = 2500;
	char password[50]; /* Password length */

	srand(time(NULL));
	while (ascii > 126)
	{
		random = rand() % 126;
		password[i] = random;
		ascii -= random;
		i++;
	}
	if (ascii > 0)
		password[i] = ascii;
	else
	{
		i--;
	}

	for (j = 0; j <= i; j++)
	{
		printf("%c", password[j]);
	}
	return (0);
}