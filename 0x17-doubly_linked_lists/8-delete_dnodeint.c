#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index
 * @head: Head of the list
 * @index: Index of the new node
 * Return: 1 if it succeeded, otherwise -1
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *h1 = *head;
	dlistint_t *h2;
	unsigned int x;


	if (h1 != NULL)
		while (h1->prev != NULL)
			h1 = h1->prev;

	x = 0;

	while (h1 != NULL)
	{
		if (x == index)
		{
			if (x == 0)
			{
				*head = h1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				h2->next = h1->next;

				if (h1->next != NULL)
					h1->next->prev = h2;
			}

			free(h1);
			return (1);
		}
		h2 = h1;
		h1 = h1->next;
		x++;
	}

	return (-1);
}
