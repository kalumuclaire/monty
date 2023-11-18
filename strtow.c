#include "monty.h"
#include "lists.h"

/**
 * count_word - Helper function to count the amount of words in a string.
 * @s: String to check.
 *
 * Return: Quantity of words.
 */
int count_word(char *s)
{
	int flag, c, w;

	flag = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}
/**
 * **strtow - Translates a string into words
 * @str: string to translate
 *
 * Return: Pointer to an array of string if successful
 * or NULL on error
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int p, k = 0, len = 0, words, c = 0, start, end;

	len = strlen(str);
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (p = 0; p <= len; p++)
	{
		if (isspace(str[p]) || str[p] == '\0' || str[p] == '\n')
		{
			if (c)
			{
				end = p;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = p;
	}

	matrix[k] = NULL;

	return (matrix);
}

/**
 * free_everything - Releases arrays of strings.
 * @args: Array of strings to be released
 */
void free_everything(char **args)
{
	int c;

	if (!args)
		return;

	for (c = 0; args[c]; c++)
		free(args[c]);

	free(args);
}
