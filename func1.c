#include "monty.h"
/**
 * push - add node at the top of stack
 * @stack: point to the head of stack
 * @line_number: line number of instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (global.arg == NULL)
	{
		free_stack(*stack);
		stderr_int(line_number);
	}
	if (!_isdigit() || stack == NULL)
	{
		free_stack(*stack);
		stderr_int(line_number);
	}
	n = atoi(global.arg);
	if (*stack  == NULL)
		new_stack_node(stack, n);
	else
		new_node_end(stack, n);
}

/**
 * pall - print stack
 * @stack: point to the head of the list
 * @line_number: instruction number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stack == NULL)
	{
		return;
	}
	if (*stack == NULL && line_number != 1)
	{
		free_stack(*stack);
		free_global();
		exit(EXIT_SUCCESS);
	}
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	while (current->prev != NULL)
	{
		printf("%d", current->n);
		current = current->prev;
		printf("\n");
	}
	printf("%d\n", current->n);
}

/**
 * pint - print the stack
 * @stack: point to head of stack
 * @line_number: instruction number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (stack == NULL || *stack == NULL)
	{
		error_pint(line_number);
		return;
	}
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	printf("%d", current->n);
	printf("\n");
}
/**
 * swap -print the stack
 * @stack: head of linkedlist
 * @line_number: number of instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int i, j;

	if (*stack == NULL || stack == NULL)
		error_fun(line_number, "swap");
	current = (*stack)->next;
	if ((*stack)->next == NULL)
		error_fun(line_number, "swap");
	while (current->next != NULL)
	{
		current = current->next;
	}
	i = current->n;
	j = current->prev->n;
	current->n = j;
	current->prev->n = i;
}
/**
 * nop - does no thing
 * @stack: point to the head of stack
 * @line_number: line of instruction
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

