/**
 * print_name - Print a name using pointer to function
 * @name: name of the person
 * @f: pointer to function
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	(*f)(name);
}
