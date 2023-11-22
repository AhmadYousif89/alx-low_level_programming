#include "lists.h"

/**
 * find_listint_loop - Find the loop using Floyd's cycle-finding algorithm
 * @head: pointer to the listint
 * Return: pointer or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hare = head, *tortoise = head;

	if (!head)
		return (NULL);

	while (tortoise && hare && hare->next)
	{
		hare = hare->next->next;
		tortoise = tortoise->next;

		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
			/* Returns the address of the node where the loop starts */
			return (hare);
		}
	}

	return (NULL); /* No loop found */
}
