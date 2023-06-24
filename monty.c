#include "monty.h"

monty_t monty = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *operation;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	monty.monty_file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		operation = NULL;
		read_line = getline(&operation, &size, file);
		monty.op = operation;
		counter++;
		if (read_line > 0)
		{
			execute(operation, &stack, counter, file);
		}
		free(operation);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
