#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int PASSWORD_LENGTH = 20;
int i, random_index;
char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";

int main()
{
	char password[100];

	/* `rand()` function will give the current time on every execution */
	srand(time(NULL));

	for (i = 0; i < PASSWORD_LENGTH; i++)
	{
		random_index = rand() % (sizeof(characters) / sizeof(char));
		password[i] = characters[random_index];
	}
	/* Add the null character at the end of the password */
	password[PASSWORD_LENGTH] = '\0';

	printf("%s", password);

	return 0;
}
