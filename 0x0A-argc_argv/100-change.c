#include <stdio.h>
#include <stdlib.h>

/**
 * main - Print the minimum number of coins challenge.
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 if successful, 1 if error
 */
int main(int argc, char *argv[])
{
	int i = 0, c = 0, arg;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	if (arg <= 1)
	{
		printf("0\n");
		return (0);
	}
	arg = atoi(argv[1]);
	while (i < sizeof(coins) / sizeof(int))
	{
		c = c + (arg / coins[i]);
		arg = arg % coins[i];
		i++;
	}
	printf("%d\n", c);

	return (0);
}
