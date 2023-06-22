#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
			break;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
 * f_stack - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	global.lifi = 0;
}
/**
 * rotr- rotates the stack to the bottom
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *buf;

	buf = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;
	while (buf->next)
		buf = buf->next;
	buf->next = *head;
	buf->prev->next = NULL;
	buf->prev = NULL;
	(*head)->prev = buf;
	(*head) = buf;
}

/**
 * rotl- rotates the stack to the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *temp = *head, *current;

	if (*head == NULL || (*head)->next == NULL)
		return;
	current = (*head)->next;
	current->prev = NULL;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = current;
}

