#include "monty.h"
global_var var_global;
/**
 * main - The driver function for monty.
 * @ac: Int number of arguments.
 * @av: File opcode.
 * Return: 0 (zero)
 */
int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(av[1], &stack);
    /* recordar liberar memorias */
	free_dlistint(stack);
	return (0);
}
