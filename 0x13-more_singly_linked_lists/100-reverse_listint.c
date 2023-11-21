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

	while (cur != NULL)
	{
		cur = (*head)->next;  /* Move to the next node */
		(*head)->next = prev; /* Reverse the link */
		prev = *head;		  /* Move to the next pair of nodes */
		*head = cur;		  /* Move to the next pair of nodes */
	}

	*head = prev;

	return (*head);
}
