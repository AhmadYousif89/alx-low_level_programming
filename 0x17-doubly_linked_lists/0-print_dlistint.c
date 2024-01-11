#include "lists.h"

/**
 * print_dlistint - Print all the elements of a doubly linked list.
 * @h: pointer to the head of dlistint
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *ptr = h;
	int count = 0;

	if (!h)
		return (0);
	while (ptr)
	{
		printf("%d\n", ptr->n);
		count++;
		ptr = ptr->next;
	}

	return (count);
}
