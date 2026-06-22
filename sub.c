#include "monty.h"

/**
 * sub - subtracts the top element from the second top element
 * @stack: pointer to stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	second->n -= top->n;

	*stack = second;
	second->prev = NULL;

	free(top);
}
