#include "monty.h"

/**
 * main - Monty interpreter entry point
 * @argc: argument count
 * @argv: arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *opcode;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		int i = 0;

		line_number++;

		/* skip leading spaces/tabs before anything */
		while (line[i] == ' ' || line[i] == '\t')
			i++;

		/* skip comment lines */
		if (line[i] == '#')
			continue;

		opcode = strtok(line, " \n\t");

		/* skip empty lines */
		if (opcode == NULL)
			continue;

		execute(opcode, &stack, line_number);
	}

	free(line);
	free_stack(stack);
	fclose(file);

	return (0);
}
