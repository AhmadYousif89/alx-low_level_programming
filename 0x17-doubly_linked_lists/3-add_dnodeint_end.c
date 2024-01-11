#include "lists.h"

/**
 * add_dnodeint_end - Add new node at the end of a doubly linked list.
 * @head: pointer to the head of dlistint
 * @n: the data as a number
 * Return: pointer to the new element or NULL on failuer
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *temp, *new = malloc(sizeof(dlistint_t));
	/* Avoid derefrencing NULL pointers */
	if (!head || !new)
		return (NULL);
	/* Create new node */
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	/* Case of empty list */
	if (!*head)
	{
		*head = new;
		return (new);
	}

	temp = *head;
	/* Traverse to the end of the list */
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;

	return (new);
}
