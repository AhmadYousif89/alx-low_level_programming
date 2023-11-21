#include "lists.h"

/**
 * free_listint2 - Free allocated memory and set head to NULL
 * @head: pointer to the list
 * Return: Nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	if (!head || !*head)
		return;

	while (*head)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}

	current = NULL;
}
