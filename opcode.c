#include "monty.h"
#include <string.h>

void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
	int i;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", div_op},
		{"mul", mul},
		{"nop", nop},
		{"pchar", pchar},
		{NULL, NULL}
	};

	if (!opcode)
		return (NULL);

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
			return (ops[i].f);
	}

	return (NULL);
}
