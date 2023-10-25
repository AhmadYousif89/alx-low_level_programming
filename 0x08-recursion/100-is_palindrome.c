/**
 * _helper - Check if a string is palindrome
 * @s: pointer type char
 * @start: starting index of the string
 * @end: ending index of the string
 * Return: 1 if palindrome, 0 otherwise
 */
int _helper(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	if (s[start] != s[end - 1])
		return (0);

	return (_helper(s, start + 1, end - 1));
}

/**
 * is_palindrome - Check for palindrome string | recursion
 * @s: pointer type char
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int length = 0;

	while (s[length] > '\0')
		length++;

	return (_helper(s, 0, length));
}
