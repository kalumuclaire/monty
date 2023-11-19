#include "monty.h"

/**
 * read_textfile - It reads text file.
 * @filename: Pointer.
 * Return: Buffer with file content
 */
FILE *read_textfile(char *filename)
{
	FILE *fd;

	fd = fopen(filename, "r");

	if (!fd)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
