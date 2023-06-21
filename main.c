#include "monty.h"
data_t data = {NULL, NULL, NULL, 0};
/**
 * main - monty code interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *token = NULL;
	size_t line_buf = 0;
	int line_num = 0, flag = 0, flag2 = 0;
	ssize_t line_size;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.el_p = fopen(argv[1], "r");
	if (global.el_p == NULL)
	{
		stderr_fopen(argv[1]);
	}
	line_size = getline(&global.el_n, &line_buf, global.el_p);
	if (global.el-n[0] == '#')
		line_size = getline(&global.el_n, &line_buf, global.el_p);
	while(line_size >= 0)
	{
		flag = 0;
		flag2 = 0;
		line_num++;
		token = strtok(global.el_n, DELIM);
		global.token2 = strtok(NULL, DELIM);
		if (token == NULL)
		{
			flag2 = 1;
			nop(&stack, line_num);
		}
		if (flag2 == 0)
		{
			if (token[0] == '#')
			{
				line_size = getline(&global.el_p, &line_buf, global.el_p);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			get_builtin(token, &stack, line_num);
			line_size = getline(&global;.el_n, &line_buf, global.el_p);
		}
	}
	free_stack(stack);
	free(global.el_n);
	global.el_p = NULL;
	fclose(global.el_p);
	return (EXIT_SUCCESS);

}
