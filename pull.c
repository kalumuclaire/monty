#include "monty.h"

/**
 * _pall - prints all elements in the list stack_t.
 * @stack: head
 * @line_number: shows the number of the line
 * Return: Void.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	line_number = line_number;
	if (stack && *stack)
	{
		h = *stack;
		while (h->next)
		{
			printf("%d\n", h->n);
			h = h->next;
		}
		if (h)
			printf("%d\n", h->n);
	}
}
