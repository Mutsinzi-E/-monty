#include "monty.h"

void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *first, *last;

    (void)line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;

    first = *stack;
    last = *stack;

    while (last->next)
        last = last->next;

    *stack = first->next;
    (*stack)->prev = NULL;

    last->next = first;
    first->prev = last;
    first->next = NULL;
}
