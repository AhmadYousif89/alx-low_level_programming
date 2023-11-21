#include "lists.h"

/**
 * pop_listint - Remove the head of the listint
 * @head: pointer to pointer to the listint
 * Return: the head node’s data (n) or (0) if list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (!*head)
		return (0);

	n = (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);

	return (n);
}
