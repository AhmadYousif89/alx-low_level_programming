#include "lists.h"

/**
 * free_listint_safe - Free a linked list | safe version
 * @h: pointer to the listint
 * Return: nodes count
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *slow = *h, *fast = *h, *temp = NULL;

	if (!h || !*h)
		return (0);

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		/* If a loop is detected, break out of the loop */
		if (slow == fast)
			break;
	}

	if (slow == fast)
	{
		/* Loop detected, move one pointer to the start and keep the other at the collision point */
		slow = *h;
		while (slow != fast)
		{
			temp = slow;
			slow = slow->next;
			free(temp);
			size++;
		}

		/* Move both pointers until they meet again (end of loop) */
		while (fast->next != slow)
		{
			temp = fast;
			fast = fast->next;
			free(temp);
			size++;
		}
	}
	else
	{
		/* No loop, simply free each node */
		while (*h != NULL)
		{
			temp = *h;
			*h = (*h)->next;
			free(temp);
			size++;
		}
	}

	*h = NULL; /* Set the h to NULL after freeing the list */
	return (size);
}
