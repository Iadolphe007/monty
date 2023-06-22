#include "monty.h"

/**
 * array_len - calculates the array of a token.
 * Return: Lenght of the token.
 */
unsigned int array_len(void)
{
	unsigned int tk_len = 0;

	while (global.arg[tk_len])
	{
		tk_len++;
	}
	return (tk_len);
}
/**
 * tokerr - makes the last element of instructions as error code.
 * @error_status: type int where the error is saved as srt.
 */
void tokerr(int error_status)
{
	int tk_len = 0, i = 0;
	char *current = NULL;
	char *new = NULL;

	tk_len = array_len();
	new = malloc(sizeof(char *) * (tk_len + 2));

	if (!global.arg)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_global();
		exit(EXIT_FAILURE);
	}
	while (i < tk_len)
	{
		new[i] = global.arg[i];
		i++;
	}
	current = get_integer(error_status);
	if (!current)
	{
		free(global.arg);
		fprintf(stderr, "Error: malloc failed\n");
		free_global();
		exit(EXIT_FAILURE);
	}
	free(global.arg);
	global.arg = new;
}

