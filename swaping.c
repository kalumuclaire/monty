#include "monty.h"

/**
 * _swap - It swaps the first two elements of the stack.
 * @stack: head.
 * @line_number: line
 * Return: Void
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack, *next_node;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		next_node = node->next;
		node->prev = *stack;
		node->next = next_node->next;
		next_node->prev = NULL;
		next_node->next = node;
		(*stack) = next_node;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
