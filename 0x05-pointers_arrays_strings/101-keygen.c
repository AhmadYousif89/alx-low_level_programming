#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The length of the password.
#define PASSWORD_LENGTH 12

char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";

char *generate_password()
{
	char *password = malloc(PASSWORD_LENGTH + 1);
	if (password == NULL)
	{
		printf("Error allocating memory for password.\n");
		return NULL;
	}
	// `rand()` function will give the current time on every execution.
	srand(time(NULL));

	for (int i = 0; i < PASSWORD_LENGTH; i++)
	{
		int random_index = rand() % (sizeof(characters) / sizeof(char));
		password[i] = characters[random_index];
	}
	/* Add the null character at the end of the password*/
	password[PASSWORD_LENGTH] = '\0';

	return password;
}

int main()
{
	char *password = generate_password();
	printf("%s\n", password);
	// Free the memory allocated for the password.
	free(password);

	return 0;
}
