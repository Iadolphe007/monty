#include "monty.h"

/**
 * get_integer - get char pointer to new str with int
 * @num: number to be converted to string
 * Return: char point NULL on fail and malloc
 */

char *get_integer(int num)
{
	long num_v = 0;
	unsigned int temp;
	int len = 0;
	char *buf;

	temp = absolut(num);
	len = buff_len(temp, 10);

	if (num < 0 || num_v < 0)
		len++;
	buf = malloc(len + 1);
	if (!buf)
		return (NULL);
	full_buf(temp, 10, buf, len);
	if (num < 0 || num_v < 0)
		buf[0] = '-';
	return (buf);
}
/**
 * absolut -  return abs of int
 * @i: integer
 * Return: i
 */
unsigned int absolut(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * buff_len - length of buffer
 * @num: number to get length needed for
 * @base: base of number representation
 * Return: length of buff
 */

int buff_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}
/**
 * full_buf - complet buff with numbers
 * @num: number to convert to string
 * @base: base number
 * @buff: bufer to ne completed
 * @buff_size: size of buffer
 */

void full_buf(unsigned int num, unsigned int base, char *buff, int buff_size)
{
	int i, x = buff_size - 1;

	while (x >= 0)
	{
		i = num % base;
		if (i > 9)
			buff[x] = i + 87;
		else
			buff[x] = i + '0';
		num /= base;
		x--;
	}
}

/**
 * _isdigit - check for int
 * Return: 0
 */
int _isdigit(void)
{
	int x = 0;

	if (global.arg[0] == '-' || global.arg[0] == '+')
		x++;
	while (global.arg[x])
	{
		if (isdigit(global.arg[x] == 0))
		{
			return (0);
		}
		x++;
	}
	return (1);
}
