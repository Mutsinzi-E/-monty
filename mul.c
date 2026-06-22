#include "monty.h"

/**
 * mul - multiplies the second top element by the top element
 * @stack: pointer to stack
 * @line_number: line number of instruction
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	second->n *= top->n;

	*stack = second;
	second->prev = NULL;

	free(top);
}
