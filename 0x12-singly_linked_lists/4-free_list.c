#include "lists.h"

/**
 * free_list - Free previously allocated memory for the list struct
 * @head: pointer to the list
 * Return: Nothing
 */
void free_list(list_t *head)
{
	list_t *current;

	if (!head)
		return;

	while (head)
	{
		current = head;
		head = head->next;
		free(current->str);
		free(current);
	}
}
