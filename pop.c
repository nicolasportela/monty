#include "monty.h"

/**
 * pop - deletes last element added to the stack
 * @stack: pointer to stack
 * @line_number: line read
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *prev = NULL;
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		*stack = NULL;
		free(current);
		return;
	}

	while (current->next != NULL)
		current = current->next;

	prev = current->prev;
	prev->next = NULL;
	free(current);
}
