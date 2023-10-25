/**
 * is_prime_number - Check for prime number | recursion
 * @n: number to check
 * Return: 1 or 0
 */
int is_prime_number(int n)
{
	int start = 2;

	if (n <= 1 || n % start == 0)
		return (0);
	if (n > 1 && n % start != 0)
		return (1);

	start++;
	return (is_prime_number(n + 1));
}
