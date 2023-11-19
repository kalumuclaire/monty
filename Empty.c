#include "monty.h"
/**
 * isEmpty - verifies if buffer is empty
 * @buffer: buffer
 * Return: returns 1 if Empry, 0 if not
 */
int isEmpty(char *buffer)
{
	int i = 0;

	while (buffer[i])
	{
		if (buffer[i] != ' ' && buffer[i] != '\t')
			return (0);
		i++;
	}

	return (1);
}
