#include "monty.h"
/**
 * free_list - function to Free a doubly linked list
 * @head: Linked list
 */
void free_list(stack_t *head)
{
	stack_t *aux;

	while (head)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}
