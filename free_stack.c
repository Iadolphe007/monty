#include "monty.h"

/**
 * free_stack - fress a doubly linked list
 * @head: point to the head pf stack
 */
void free_stack(stack_t *head)
{
	stack_t *current = NULL;
	stack_t *temp = NULL;

	temp = head;

	while (current != NULL)
	{
		current = temp->next;
		free(temp);
		temp = current;
	}
}

/**
 * free_global - frees global list
 */
void free_global(void)
{
	fclose(global.el_p);
	free(global.el_n);

}
