#include "monty.h"

global_t gl;
/**
 * _pint - Prints the top of the stack value, a new line next.
 * @stack: Stack head.
 * @line_number: Number of line.
 * Return: Void.
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !stack)
	{
		free(gl.buffer), free_list(*stack), fclose(gl.fd);
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
