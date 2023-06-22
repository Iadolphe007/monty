#include "monty.h"

global_t global = {NULL, NULL, NULL};
#define MAX_LINE_LENGTH 1024

/**
 * process_line - Process a single line of Monty code
 * @line: The line to process
 * @stack: Pointer to the stack
 * @line_num: Line number
 */
void process_line(char *line, stack_t **stack, int line_num)
{
	char *token;

	token = strtok(line, DELIMS);

	if (token == NULL)
	{
		nop(stack, line_num);
		return;
	}
	if (token[0] == '#')
		return;
	get_builtin(token, stack, line_num);
}
/**
 * main - Monty code interpreter
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	char line[MAX_LINE_LENGTH];
	int line_num = 0;
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
		stderr_usage();
	
	file = fopen(argv[1], "r");
	if (file == NULL)
		stderr_fopen(argv[1]);

	while (fgets(line, sizeof(line), file))
	{
		line_num++;
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		process_line(line, &stack, line_num);
	}
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
