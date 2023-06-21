#include "monty.h"

/**
 * new_stack_node - create stack node in front
 * @stack: pointer to the stack
 * @n: value
 * Return: new node
 */

stack_t *new_stack_node(stack_t **stack, int n)
{
	stack_t *new_stack;
	stack_t *current;

	if (stack == NULL)
		return (NULL);
	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_global();
		exit(EXIT_FAILURE);
	}
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = new_stack;
	new_stack-> = n;
	new_atack->prev = current;
	new_stack->nexr = NULL;
	return (new_stack);
}

/**
 * new_node_end - add new stack node at the end
 * @stack: a pointer to stack
 * @n:value
 * Return: new node at the end
 */

stack_t *new_node_end(stack_t **stack, int n)
{
	stack_t *new_node;
	stack_t *current;

	if (stack == NULL)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		 fprintf(stderr, "Error: malloc failed\n");
		 free_global();
		 exit(EXIT_FAILURE);
	}
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	new_node->n = n;
	new_node->prev = current;
	new_node->next = NULL;
	return (new_node);
}
/**
 * add_node_front - add new node at the beginning of the list
 * @head: pointer to the first element of the list
 * @n: integer value
 * Return: pointer to a new node at the beginning of the list
 */
stack_t add_node_front(stack_t **head, int n)
{
	stack_t new_node = NULL;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node-> = n;
	if (*head == NULL)
	{
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	new_node->n = n;
	(*head)->prev = new_node;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
