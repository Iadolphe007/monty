#include "monty.h"

/**
 * stack_node - create stack
 * @stack: pointer to top aof a stack
 * Retrun 0
 */

int stack_node(stack_t **stack)
{
	stack_t *tmp;

	tmp =  malloc(sizeof(stack_t));
	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_global();
		exit(EXIT_FAILURE);
	}
	tmp->n = STACK;
	tmp->prev = NULL;
	tmp->next = NULL;
	*stack = stack;
	return(0);
}
/**
 * free_node - free node at stack
 * @stack: point to stack
 */
void free_node(stack_t **stack)
{
	stack_t *tmp = *stack;

	while(*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
/**op_check - check for stack or queue
 * @stack: a pointer to stack
 * Return: value of stack or queue
 */

int op_check(stack_t *stack)
{
	int ret_val = 2;

	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return(ret_val);
}
