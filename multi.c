#include "monty.h"

/**
 * _mul - Adds together the top two stack elements.
 * @stack: Stack head.
 * @line_number: Line number.
 * Return: Void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (aux && aux->next)
	{
		aux = aux->next;
		aux->n = aux->n * (*stack)->n;
		_pop(stack, line_number);
	}
	else
	{
		free(gl.buffer), free_list(*stack), fclose(gl.fd);
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
