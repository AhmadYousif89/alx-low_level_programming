#include "lists.h"

/**
 * add_dnodeint - Add new node at the beginning of a doubly linked list.
 * @head: pointer to the head of dlistint
 * @n: the data as a number
 * Return: pointer to the new element or NULL on failuer
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));
	/* Avoid derefrencing NULL pointers */
	if (!head || !new)
		return (NULL);
	/* Create new node */
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	/* Add new node to the beginning */
	if (*head)
	{
		new->next = *head;
		(*head)->prev = new;
	}
	*head = new;

	return (new);
}
