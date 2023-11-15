#include "monty.h"
/**
 * read_file - Reads the bytecode file, runs its commands.
 * @filename: Pathname (to file)
 * @stack: Pointer to the stack top.
 */
void read_file(char *filename, stack_t **stack)
{
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func s;
	int check;
	int read;


	var_global.file = fopen(filename, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&var_global.buffer, &i, var_global.file)) != -1)
	{
		line = parse_line(var_global.buffer, stack, line_count);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_op_func(line);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}
		s(stack, line_count);
		line_count++;
	}
	free(var_global.buffer);
	check = fclose(var_global.file);
	if (check == -1)
		exit(-1);
}

/**
 * get_op_func -  Checks opcode also returns correct function.
 * @str: opcode
 * Return: returns a function, NULL on failure
 */
instruct_func get_op_func(char *str)
{
	int c;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL},
	};

	c = 0;
	while (instruct[c].f != NULL && strcmp(instruct[c].opcode, str) != 0)
	{
		c++;
	}

	return (instruct[c].f);
}

/**
 * isnumber - Checks if the string is a numeral.
 * @str: String to be passed.
 * Return: 1 if string is a number, 0 if not.
 */
int isnumber(char *str)
{
	unsigned int c;

	if (str == NULL)
		return (0);
	c = 0;
	while (str[c])
	{
		if (str[0] == '-')
		{
			c++;
			continue;
		}
		if (!isdigit(str[c]))
			return (0);
		c++;
	}
	return (1);
}

/**
 * parse_line - parses a line for an opcode and arguments
 * @line: Line being parsed.
 * @stack: Pointer to stack’s head.
 * @line_number: Current line numeral
 * Return: The opcode, null on failure.
 */
char *parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *op_code, *push, *arg;
	(void)stack;

	push = "push";
	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnumber(arg) == 1 && arg != NULL)
		{
			var_global.push_arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}
