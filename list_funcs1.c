#include "monty.h"

/**
 * dlistint_len - Returns the quantity of nodes in a doubly linked list.
 * @h: list pointer.
 *
 * Return: Quantity of nodes.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}

/**
 * add_dnodeint - Puts a new node at the start of a doubly linked list.
 * @head: List’s double pointer.
 * @n: Data put in the new node.
 *
 * Return: The address of the new element, NULL if it fails.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;

	new->next = *head;
	new->prev = NULL;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
 * print_dlistint - It prints a doubly linked list.
 * @h: pointer.
 *
 * Return: Quantity of nodes in the list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodes++;
	}

	return (nodes);
}

/**
 * delete_dnodeint_at_index - Removes a node in a doubly linked list
 * at a specified index.
 * @head: The list’s double pointer
 * @index: Index of the node to be deleted.
 *
 * Return: 1 if successful, -1 if it fails
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int c = 0;

	if (!index)
	{
		(*head) = temp->next;
		if (temp->next)
			temp->next->prev = NULL;
		temp->next = NULL;
		free(temp);
		return (1);
	}

	while (c < index)
	{
		temp = temp->next;
		c++;
		if (!temp)
			return (0);
	}

	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);

	return (1);
}

/**
 * get_dnodeint_at_index - Obtains the nth node of a doubly linked list.
 * @head: list’s pointer.
 * @index: Index of the node to be returned.
 *
 * Return: Node’s address, or NULL if it does not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int c = 0;

	if (!head)
		return (NULL);

	while (head && c < index)
	{
		head = head->next;
		c++;
	}

	return (head ? head : NULL);
}
