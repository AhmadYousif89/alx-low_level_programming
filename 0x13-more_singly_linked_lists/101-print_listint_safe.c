#include "lists.h"

/**
 * print_listint_safe - Print-safe the nodes in listint
 * @head: pointer to the list
 * Return: nodes count
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t i, nc = 0;
	const listint_t *current = head, *next = NULL;

	while (current)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		nc++;

		current = current->next;
		next = head;
		i = 0;
		while (i < nc)
		{
			if (current == next)
			{
				printf("-> [%p] %d\n", (void *)current, current->n);
				return (nc);
			}
			next = next->next;
			i++;
		}
	}

	if (!head)
		exit(98);

	return (nc);
}
