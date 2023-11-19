#include "monty.h"
global_t gl;
/**
 * next_word - Function that sets the global variable.
 * @word: Buffer.
 * Return: Void.
 */
void next_word(char *word)
{
	int a = 0, flag = 0, global;

	if (!word)
	{
		gl.n = -255;
		return;
	}

	if (strcmp(word, "0") == 0)
		global = 0;
	else
	{
		if (word[0] == '-')
			a++;
		while (word[a])
		{
			if (word[a] < '0' || word[a] > '9')
				flag = 1;
			a++;
		}
		global = atoi(word);
		if (global == 0 || flag == 1 || word == NULL)
			global = -255;
	}
	gl.n = global;
}
