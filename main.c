#include "monty.h"

/**
 * main - interpreter for monty op-codes
 * @argc: argument counter. Only 2 are accepted
 * @argv: array of arguments
 * Return: 0 on successful execution
 */

int main(int argc, char **argv)
{
	FILE *file_d;
	int len_name, ret;
	char *file_name;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_name = argv[1];

	len_name = strlen(file_name);

	if (file_name[len_name - 1] != 'm' && file_name[len_name - 2 != '.'])
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	file_d = fopen(file_name, "r");
	if (file_d == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	ret = read_func(file_d);
	if (ret == 1)
	{
		fclose(file_d);
		exit(EXIT_FAILURE);
	}
	fclose(file_d);

	return (0);
}
