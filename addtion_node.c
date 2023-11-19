#include "monty.h"
/**
 * add_dnodeint_end - this function add a new node
 * @head: head
 * @n: shows the value of new node
 * Return: returns new node of the address
 */
stack_t *add_dnodeint_end(stack_t **head, int n)
{
	stack_t *new = NULL, *aux = *head;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head)
	{
		while (aux->next)
		{
			aux = aux->next;
		}
		aux->next = new;
		new->prev = aux;
	}
	else
	{
		new->prev = NULL;
		*head = new;
	}
	return (new);
}
