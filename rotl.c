#include "monty.h"
/**
 * _rotl - Function used to push.
 * @stack: Stack
 * @line_number: Line.
 * Return: a Void
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack, *new;
	int c;

	if (*stack && aux->next)
	{
		c = (*stack)->n;
		_pop(stack, line_number);
		while (aux->next)
			aux = aux->next;
		new = malloc(sizeof(stack_t));
		new->next = NULL;
		new->n = c;
		new->prev = aux;
		aux->next = new;
	}
}
