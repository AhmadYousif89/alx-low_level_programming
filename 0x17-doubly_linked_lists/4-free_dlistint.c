#include "lists.h"

/**
 * free_dlistint - Free a doubly linked list.
 * @head: pointer to the head of dlistint
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current = head, *next;

	if (!head)
		return;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
