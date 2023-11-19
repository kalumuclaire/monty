#include "monty.h"
/**
 * _rotr - Push function.
 * @stack: Head.
 * @line_number: line number
 * Return: Void.
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack, *aux2 = *stack, *auxpr;

	line_number = line_number;
	if (*stack && stack && aux->next)
	{
		while (aux)
		{
			aux2 = aux->next;
			auxpr = aux->prev;
			aux->next = auxpr;
			aux->prev = aux2;
			aux = aux2;
		}
		*stack = auxpr->prev;
	}
}
