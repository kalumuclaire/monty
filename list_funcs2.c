#include "monty.h"
#include "lists.h"

/**
 * insert_dnodeint_at_index - Introduces a node at a specified index
 * in a doubly linked list.
 * @h: Double pointer to list.
 * @idx: Index of the inserted node.
 * @n: Information data to be inserted.
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int c;
	dlistint_t *new;
	dlistint_t *temp = *h;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (c = 0; temp && c < idx; c++)
	{
		if (c == idx - 1)
		{
			if (temp->next == NULL)
				return (add_dnodeint_end(h, n));
			new = malloc(sizeof(dlistint_t));
			if (!new || !h)
				return (NULL);
			new->n = n;
			new->next = NULL;
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}

/**
 * add_dnodeint_end - Puts new node at the end of a doubly linked list.
 * @head: List’s double pointer
 * @n: Data to introduce in new node
 *
 * Return: The new element’s address, NULL on failure.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *temp = *head;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;

	return (new);
}

/**
 * free_dlistint - Releases a doubly linked list.
 * @head: Pointer to list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
