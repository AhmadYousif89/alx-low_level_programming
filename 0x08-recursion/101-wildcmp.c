/**
 * wildcmp - Compares two strings and return a number | recursion
 * @s1: pointer type char
 * @s2: pointer type char
 * Return: 1 if identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* Case 1: both strings are empty, they are considered identical */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	/* Case 2: s2 has a wildcard '*' */
	if (*s2 == '*')
	{
		/* Move s2 until it reaches the next character after '*' */
		s2++;
		/*  We try to match evry character in s2 with s1*/
		while (*s1 != '\0')
		{
			if (wildcmp(s1, s2))
				return (1);
			s1++;
		}
		/* If '*' is the last char in s2 */
		/* that means that s2 can match any char in s1 so we return (1) */
		if (*s2 == '\0')
			return (1);
		/* Case 3: we didn't find any matching characters with s1 */
		return (0);
	}
	/* Case 4: s2 has no '*' and didn't match any character in s1 */
	if (*s1 != *s2)
		return (0);
	/* Move to the next character position in both strings */
	return (wildcmp(s1 + 1, s2 + 1));
}
