#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node
 * @head: Pointer
 * @index: Index of the node to search for.
 * Return: The nth node or null
 **/

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int size = 0;
	dlistint_t *tmp;

	if (head == NULL)
	return (NULL);

	tmp = head;
	while (tmp)
	{
	if (index == size)
	return (tmp);
	size++;
	tmp = tmp->next;
	}
	return (NULL);
}
