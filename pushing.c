#include "monty.h"
global_t gl;
/**
 * _push - Push function.
 * @stack: stack
 * @line_number: Line num
 * Return: Void.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int j = gl.n;

	if (j != -255)
	{
		if (gl.mode == 's')
			add_nodo(stack, j);
		else
			add_dnodeint_end(stack, j);
	}
	else
	{
		free(gl.buffer), free_list(*stack), fclose(gl.fd);
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * add_nodo - Function used to push.
 * @stack: stack
 * @a: Line num
 * Return: Void.
 */
void add_nodo(stack_t **stack, int a)
{
	stack_t *new = malloc(sizeof(stack_t)), *aux;

	new->n = a;
	new->prev = NULL;
	if (!stack || !(*stack))
	{
		new->next = NULL;
		*stack = new;
	}
	else
	{
		aux = *stack;
		aux->prev = new;
		new->next = aux;
		*stack = new;
	}
}
