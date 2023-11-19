#include "monty.h"

/**
 * _pstr - Prints string beginning from the top of the stack,
 * followed by a new line.
 * @stack: Stack Head
 * @line_number: Number of line.
 * Return: Void.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	line_number = line_number;

	if (*stack || stack)
	{
		while (temp && temp->n != 0)
		{
			if ((temp->n <= 0 || temp->n > 127))
			{
				break;
			}
			putchar(temp->n);
			temp = temp->next;
		}
		printf("\n");
	}
	else
	printf("\n");
}
