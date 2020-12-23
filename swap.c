#include "monty.h"

/**
 * swap - Swap the top two elements of stack
 * @stack: Doubly linked list
 * @line_number: Line's number
 * Return: Nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *prev = NULL;
	stack_t *current = *stack;
	int count = 1, val_cur, val_prev;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	prev = current->prev;
	val_cur = current->n;
	val_prev = prev->n;
	prev->n = val_cur;
	current->n = val_prev;
}
