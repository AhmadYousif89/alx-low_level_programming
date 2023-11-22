#include "lists.h"

/**
 * free_listint_safe - Free a linked list | safe version
 * @h: pointer to the listint
 * Return: nodes count
 */
size_t free_listint_safe(listint_t **h)
{
	size_t nc = 0;
	listint_t *current = *h;
	listint_t *next_node;

	while (current)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		nc++;

		next_node = current->next;
		free(current);
		current = next_node;

		if (current == *h)
		{
			free(*h);
			*h = NULL;
			nc++;
			break;
		}
	}

	*h = NULL;
	return (nc);
}
