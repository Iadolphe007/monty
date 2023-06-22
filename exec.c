#include "monty.h"

/**
 * get_builtin - Parses the instruction with the function
 * @token: type pointer extern var char
 * @stack: type pointer node of data struct
 * @line_number: line of instructions
 * Return: 0 on sucess
 */
int get_builtin(char *token, stack_t **stack, unsigned int line_number)
{
	instruction_t op_code[] = {
		{ "push", push },
		{ "pall", pall },
		{ "nop", nop },
		{ "pint", pint },
		{ "swap", swap },
		{ "pop", pop },
		{ "add", add },
		{ "sub", sub },
		{ "mul", mul },
		{ "pchar", pchar },
		{NULL, NULL}
	};

	int i, flag  = 0;
	char *argument = NULL;

	if (stack == NULL || token == NULL)
		return (0);
	argument = token;
	for (i = 0; op_code[i].opcode; i++)
	{
		if (strcmp(argument, op_code[i].opcode) == 0)
		{
			flag = 1;
			op_code[i].f(stack, line_number);
			break;
		}
	}
	if (flag == 0)
		stderr_unknown(token, line_number);
	return (0);
}
