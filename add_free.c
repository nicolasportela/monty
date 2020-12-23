#include "monty.h"

/**
 * add_int - add node at the end of stack
 * @stack: pointer to first element
 * @line_number: line being read
 */

void add_int(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	stack_t *act = *stack;
	(void)line_number;

	if (*stack == NULL)
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
			return;
		new->n = op_value;
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
		return;
	}
	else
	{
		while (act->next != NULL)
		{
			act = act->next;
		}
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new->n = op_value;
		new->prev = act;
		new->next = NULL;
		act->next = new;
	}
}

/**
 * add_func - add two last val from stack and assign it to previous.
 * @stack: stack to look for.
 * @line_number: number of line to get analyzed.
 */

void add_func(stack_t **stack, unsigned int line_number)
{
	stack_t *prev = NULL;
	stack_t *current = *stack;
	int count = 1, add_value;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	prev = current->prev;
	add_value = current->n + prev->n;
	prev->n = add_value;
	prev->next = NULL;
	free(current);
}

/**
 * free_stack - free memory of stack before finishing program
 * @stack: pointer to first element
 */

void free_stack(stack_t *stack)
{
	stack_t *save = stack;

	if (stack == NULL)
	{
		return;
	}
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	while (stack != NULL)
	{
		save = stack;
		stack = stack->prev;
		free(save);
	}
}
