#include "lists.h"

/**
 * free_listint - Free allocated memory for the listint_t struct
 * @head: pointer to the list
 * Return: Nothing
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	if (!head)
		return;

	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
