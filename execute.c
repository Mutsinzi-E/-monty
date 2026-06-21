#include "monty.h"

/**
 * execute - executes the correct opcode function
 * @opcode: instruction string
 * @stack: pointer to stack
 * @line_number: current line number
 *
 * Return: void
 */
void execute(char *opcode, stack_t **stack, unsigned int line_number)
{
	void (*func)(stack_t **, unsigned int);

	if (!opcode)
		return;

	func = get_op_func(opcode);

	if (func == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}

	func(stack, line_number);
}
