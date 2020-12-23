#include "monty.h"

/**
 * p_stack - print elements of the stack, from the last one added
 * @stack: pointer to stack
 * @line_number: line number read
 */

void p_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	if (*stack == NULL)
		return;

	while (current->next != NULL)
	{
		current = current->next;
	}
	while (current->prev != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
	printf("%d\n", current->n);
}

/**
 * print_error - print error in case that the line doesn't have correct op_code
 * @line_number: line number read
 * @op_c: command read
 */

void print_error(unsigned int line_number, char *op_c)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op_c);
}


/**
 * p_int - print the top element of the stack(last added)
 * @stack: pointer to stack
 * @line_number: line number read
 */

void p_int(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	printf("%d\n", current->n);
}
