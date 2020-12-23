#include "monty.h"

/**
 * read_func - reads each line of the file and sends it the the run funcion
 * @file_d: file received from the fopen funcion in main
 * Return: 0 en successful execution. 1 in case of error
 */

int read_func(FILE *file_d)
{
	char *line = malloc(128);
	unsigned int line_number = 1;
	int ret;
	stack_t *stack = NULL;

	while (fgets(line, 128, file_d))
	{
		ret = run(line, &stack, line_number);
		if (ret == 1)
		{
			free(line);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	free(line);
	free_stack(stack);
	return (0);
}
