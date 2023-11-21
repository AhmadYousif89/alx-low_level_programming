#include "lists.h"

/**
 * reverse_listint - Reverse nodes inside listint
 * @head: pointer to the pointer of listint
 * Return: pointer to the head or NULL
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *cur = *head, *prev = NULL;

	if (!head || !*head)
		return (NULL);

	while (cur)
	{
		/* Save the next node by assigning it to (cur) */
		cur = (*head)->next;
		/* Reverse the list by assigning the next node to (prev) */
		(*head)->next = prev;
		/* Move to the next pair of nodes */
		prev = *head;
		*head = cur;
	}
	/* Update the head to the new head (prev) */
	*head = prev;

	return (*head);
}
