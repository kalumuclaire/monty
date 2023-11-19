#include "monty.h"
/**
 * errounk - asdi
 * @line: line
 * @aux: aux
 */
void errounk(unsigned int line, char *aux)
{
	int j = 0;

	while (aux[j])
	{
		if (aux[j] == ' ')
			break;
	j++;
	}
	dprintf(2, "L%u: unknown instruction %s\n", line, aux);
	aux[j] = ' ';
	free(aux);
	exit(EXIT_FAILURE);
}
