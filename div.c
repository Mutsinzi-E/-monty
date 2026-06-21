#include "monty.h"

/**
 * div_op - divides second top by top element
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int result;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = second->n / first->n;

	second->n = result;
	*stack = second;
	second->prev = NULL;

	free(first);
}
