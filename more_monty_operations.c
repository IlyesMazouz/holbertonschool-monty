#include "monty.h"
#include "stdlib.h"

/**
 * add - adds the top two elements of the stack
 * @stack: a double pointer
 * @line_number: an unsigned integer
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *top = *stack;
	*stack = (*stack)->next;
	(*stack)->n += top->n;
	(*stack)->prev = NULL;
	free(top);
}