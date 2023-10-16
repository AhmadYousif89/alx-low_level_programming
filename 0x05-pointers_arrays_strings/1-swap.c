/**
 * swap_int - Swap the value of 2 ints in memory
 * @a: pointer of type int
 * @b: pointer of type int
 */
void swap_int(int *a, int *b)
{
	int s = *a; /* Store the value of (a) before swaping */
	*a = *b;	/* Value of (a) is equal to (b) */
	*b = s;		/* Value of (b) is equal to (p) == (a) */
}
