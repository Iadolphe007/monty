#include "monty.h"

/**
 * stderr_usage - usage error.
 * Return: EXIT_FAILURE
 */
void stderr_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * stderr_malloc - Prints malloc error messages.
 * Return: EXIT_FAILURE
 */
void stderr_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_global();
	exit(EXIT_FAILURE);
}
/**
 * stderr_fopen - error of fopen.
 * @filename: type pointer char of filename
 * Return: EXIT_FAILURE
 */
void stderr_fopen(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
/**
 * stderr_int - error of int.
 * @line_number: type pointer of line number
 * Return: EXIT_FAILURE
 */
void stderr_int(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	free_global();
	exit(EXIT_FAILURE);
}
/**
 * stderr_unknown - unknown error messagess.
 * @line_number: line number of the instruction.
 * @token: type pointer char of the instruction.
 * Return: EXIT_FAILURE
 */
void stderr_unknown(char *token, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
	free_global();
	exit(EXIT_FAILURE);
}
/**
 * error_pint - pint error message for empty stacks.
 * @line_number: line number of the instruction.
 * Return: EXIT_FAILURE
 */
void error_pint(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	free_global();
	exit(EXIT_FAILURE);
}
/**
 * error_fun - math func error messagess.
 * @line_number: line number of the instruction.
 * @op: Operation where the error occurred.
 * Return: EXIT_FAILURE
 */
void error_fun(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	free_global();
	exit(EXIT_FAILURE);

}
/**
 * error_pchar - phar error msg for 0 stack & and non-char val.
 * @line_number: line number of the instruction
 * @msg: error message to print.
 ** Return: EXIT_FAILURE.
 */
void error_pchar(unsigned int line_number, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, msg);
	free_global();
	exit(EXIT_FAILURE);
}
/**
 * error_div - error for div by 0.
 * @line_number: line number of the instruction.
 * Return: EXIT_FAILURE
 */
void error_div(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	free_global();
	exit(EXIT_FAILURE);
}
/**
 * error_pop - pop error message for empty stacks.
 * @line_number: line number of the instructions.
 * Return: EXIT_FAILURE.
 */
void error_pop(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	free_global();
	exit(EXIT_FAILURE);
}
