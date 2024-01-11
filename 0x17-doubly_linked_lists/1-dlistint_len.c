#include "lists.h"

/**
 * dlistint_len - Count all elements of a doubly linked list.
 * @h: pointer to the head of dlistint
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *ptr = h;
	int count = 0;

	if (!h)
		return (0);
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}

	return (count);
}
