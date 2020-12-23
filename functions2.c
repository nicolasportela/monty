#include "monty.h"

/**
 * s_pop - deletes last element added
 * @stack: pointer to stack
 * @line_number: number of line being read
 */

void s_pop(stack_t **stack, unsigned int line_number)
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

/**
 * nope - really?
 * @stack: stack list
 * @line_number: number of line being read
 */

void nope(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * add_func - add two last val from stack and assign it to previous.
 * @stack: stack to look for.
 * @l_n: number of line to get analyzed.
 */

void add_func(stack_t **stack, unsigned int l_n)
{
	stack_t *prev = NULL;
	stack_t *current = *stack;
	int count = 1, add_value;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	prev = current->prev;
	add_value = current->n + prev->n;
	prev->n = add_value;
	prev->next = NULL;
	free(current);
}

/**
 * swap_s - swap values from two last elements.
 * @stack: stack to look for.
 * @l_n: number of line to get analyzed.
 */

void swap_s(stack_t **stack, unsigned int l_n)
{
	stack_t *prev = NULL;
	stack_t *current = *stack;
	int count = 1, val_cur, val_prev;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	prev = current->prev;
	val_cur = current->n;
	val_prev = prev->n;
	prev->n = val_cur;
	current->n = val_prev;
}
