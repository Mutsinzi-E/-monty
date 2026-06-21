#include "monty.h"
#include <ctype.h>

/**
 * is_integer - checks if a string is a valid integer
 * @str: string to check
 *
 * Return: 1 if valid integer, 0 otherwise
 */
int is_integer(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	if (str[0] == '-' || str[0] == '+')
		i = 1;

	if (str[i] == '\0')
		return (0);

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}
