#include "lists.h"

/**
 * print_listint_safe - Print the nodes in listint
 * @head: pointer to the list
 * Return: nodes count
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nc = 0;
	const listint_t *current = head, *slow = head, *fast = head;

	if (!head)
		return (0);

	while (fast && fast->next)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		nc++;

		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
		{
			printf("-> [%p] %d\n", (void *)fast, fast->n);
			exit(98);
		}

		current = current->next;
	}

	while (current)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		current = current->next;
		nc++;
	}

	return (nc);
}
