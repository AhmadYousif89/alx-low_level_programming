/**
 * print_name - Print a name using a pointer to function
 * @name: name of the person
 * @f: pointer to the printing function
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;
	f(name);
}
