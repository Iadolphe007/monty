#include "monty.h"
/**
 * pop - Add node to the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *current = NULL;
	int i = 0, j = 0, flag = 0;

	if (stack == NULL)
	{
		free_stack(*stack);
		error_pop(line_number);
	}
	if (*stack == NULL)
	{
		free_stack(*stack);
		error_pop(line_number);
	}
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	current = *stack;
	while (j < (i - 1))
	{
		current = current->next;
		j++;
	}
	if (i == 0 && flag == 0)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	else
	{
		current->next = NULL;
		free(current);
		temp = NULL;
		return;
	}
}
/**
 * add - adds the top two elements of the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *current = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		error_fun(line_number, "add");
	}
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	current = *stack;
	while (j < (i - 1))
	{
		current = current->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_stack(*stack), error_fun(line_number, "add");
	else
	{
		current->n = current->n + temp->n;
		current->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}
/**
 * sub - subtracts the top e of stack from the 2nd top element of the stack.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *current = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
		error_fun(line_number, "sub");
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	current = *stack;
	while (j < (i - 1))
	{
		current = current->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_stack(*stack), error_fun(line_number, "sub");
	else
	{
		current->n = current->n - temp->n;
		current->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}
/**
 * pchar - Print char.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || stack == NULL)
	{
		error_pchar(line_number, "stack empty");
		return;
	}
	temp = (*stack);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	if (temp->n < 0 || temp->n > 127)
	{
		error_pchar(line_number, "value out of range");
	}
	printf("%c\n", temp->n);
}
/**
 * mul - Mul 2nd val from top of a stack_t by top value.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *current = NULL;
	int i = 0, j = 0, flag = 0;

	if (*stack == NULL || stack == NULL)
	{
		error_fun(line_number, "mul");
		return;
	}
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	current = *stack;
	while (j < (i - 1))
	{
		current = current->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_stack(*stack), error_fun(line_number, "mul");
	else
	{
		current->n = current->n * temp->n;
		current->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}
