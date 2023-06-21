#include "monty.h"

/**
 * free_stack - fress a doubly linked list
 * @head: point to the head pf stack
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;
	stack_t *temp;
	while(current !=NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
