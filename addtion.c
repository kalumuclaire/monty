#include "monty.h"

global_t gl;
/**
 * _add - this function adds the top two elements
 * @stack: stack head
 * @line_number: shows the number of the line
 * Return: void
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (aux && aux->next)
	{
		aux = aux->next;
		aux->n = aux->n + (*stack)->n;
		_pop(stack, line_number);
	}
	else
	{
		free(gl.buffer), free_list(*stack), fclose(gl.fd);
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

