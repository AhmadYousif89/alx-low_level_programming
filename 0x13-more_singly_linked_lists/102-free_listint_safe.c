#include "lists.h"

/**
 * free_listint_safe - Free a linked list | safe version
 * @h: pointer to the listint
 * Return: nodes count
 */
size_t free_listint_safe(listint_t **h)
{
	int dif;
	size_t nc = 0;
	listint_t *temp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		/* Checks the difference in addrs between the cur node and the next */
		dif = *h - (*h)->next;

		/* If dif is positive, then we are not in a loop */
		/* and the function frees the current node and moves on to the next */
		if (dif > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			nc++;
		}
		/* If dif is less than 0, then we have a loop */
		/* and the function breaks out after freeing the current node */
		else
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
