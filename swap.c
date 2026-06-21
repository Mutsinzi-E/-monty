#include "monty.h"

/**
 * swap - swaps top two elements of stack
 * @stack: stack pointer
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	temp = first->n;
	first->n = second->n;
	second->n = temp;
}
