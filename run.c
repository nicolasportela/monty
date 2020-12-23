#include "monty.h"

int op_value;

/**
 * run - reads each line and asigns value to global variable
 * @line: Line got from the read function
 * @stack: stack with nodes
 * @line_number: which line it's reading
 * Return: 0 on correc execution, 1 on error
 */

int run(char *line, stack_t **stack, unsigned int line_number)
{
	char *line_tok = NULL;
	int ret;
	char delim[] = " \n\t\r";

	instruction_t op_code[] = {
		{"push", add_int},
		{"pall", p_stack},
		{"pint", p_int},
		{"pop", s_pop},
		{"nop", nope},
		{"add", add_func},
		{"swap", swap_s},
		{NULL, NULL}
	};
	line_tok = strtok(line, delim);
	ret = loop(op_code, line_tok, stack, line_number);
	if (ret == 1)
		exit(EXIT_FAILURE);
	return (0);
}

/**
 * loop - loops through op_code to find and execute function
 * @op_c: array of struc
 * @l_t: line to check
 * @l_n: you know already
 * @s: stack
 * Return: 1 on failure, 0 on success
 */

int loop(instruction_t *op_c, char *l_t, stack_t **s, unsigned int l_n)
{
	char *value = NULL;
	int i = 0;
	char delim[] = " \n\t\r";

	while (op_c[i].opcode != NULL)
	{
		if (strcmp(op_c[i].opcode, l_t) == 0)
		{
			if (strcmp(l_t, "push") == 0)
			{
				value = strtok(NULL, delim);
				if (value == NULL || isdigit(*value) == 0)
				{
					p_error(l_n);
					exit(EXIT_FAILURE);
				}
				op_value = atoi(value);
			}
			op_c[i].f(s, l_n);
			if (checker(s, l_t) == 1)
				exit(EXIT_FAILURE);
			break;
		}
		i++;
	}
	if (op_c[i].opcode == NULL)
	{
		print_error(l_n, l_t);
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * p_error - prints error in case of incorrect value for push
 * @line_number: number of line that is being read
 */

void p_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
}

/**
 * checker - checks if the stack is empty. works with relative functions
 * @stack: stack
 * @line_tok: value of opcode(function)
 * Return: 1 if any condition is true, 0 if not
 */

int checker(stack_t **stack, char *line_tok)
{
	if (*stack == NULL && (strcmp(line_tok, "pint") == 0))
		exit(EXIT_FAILURE);
	if (*stack == NULL && (strcmp(line_tok, "s_pop") == 0))
		exit(EXIT_FAILURE);
	return (0);
}
