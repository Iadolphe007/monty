#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * global_s - carries variable
 * @el_p: pointer to monty file
 * @arg: argument
 * @el_n: line content
 * flag to change stack <-> queue
 * Description: carries values through the program
 */

typedef struct global_s
{
	char *arg;
	FILE *el_p;
	char *el_n;
} global_t;

extern global_t global;

int main(int argc, char **argv);
void process_line(char *line, stack_t **stack, int line_num);
void free_global(void);
void free_stack(stack_t *head);
int get_builtin(char *token, stack_t **stack, unsigned int line_number);

/*list function prototype*/
stack_t *add_node_front(stack_t **head, int n);
stack_t *new_node_end(stack_t **stack, int n);
stack_t *new_stack_node(stack_t **stack, int n);

int op_check(stack_t *stack);
void free_node(stack_t **stack);
int stack_node(stack_t **stack);

char *get_integer(int num);
unsigned int absolut(int i);
int buff_len(unsigned int num, unsigned int base);
void full_buf(unsigned int num, unsigned int base, char *buff, int buff_size);
int _isdigit(void);

/*mandatory task prototype*/
void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);

/* errors*/
void stderr_usage(void);
void stderr_malloc(void);
void stderr_fopen(char *filename);
void stderr_int(unsigned int line_number);
void stderr_unknown(char *token, unsigned int line_number);
void error_pop(unsigned int line_number);
void error_div(unsigned int line_number);
void error_pchar(unsigned int line_number, char *msg);
void error_fun(unsigned int line_number, char *op);
void error_pint(unsigned int line_number);

void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
#endif
