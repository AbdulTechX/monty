#include "monty.h"
#include <string.h>


/**
 * free_content - frees the global op_token array fo strings.
 */
void free_content(void)
{
	size_t index = 0;

	if (op_tokenise == NULL)
		return;

	for (index = 0; op_tokenise[index]; index++)
		free(op_tokenise[index]);
	free(op_tokenise);
}

/**
 * content_arr_len - get the length of the op_token
 *
 * Return: length of current op_token
 */
unsigned int content_arr_len(void)
{
	unsigned int toks_len = 0;

	while (op_tokenise[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_empty_line - checks if a line read from getline only contains delim
 * @lines: A pointer to the line.
 * @delim: A string of delimeter characters.
 *
 * Return: if the line only contains delimeters.
 *         return -1 othertwise 0
 */
int is_empty_line(char *lines, char *delim)
{
	int index, alteration;

	for (index = 0; lines[index]; index++)
	{
		for (alteration = 0; delim[alteration]; alteration++)
		{
			if (lines[index] == delim[alteration])
				break;
		}
		if (delim[alteration] == '\0')
			return (0);
	}

	return (1);
}

/**
 * exe_op_func - execute operation code that matches the functions
 * @opcode: the opcode to match
 *
 * Return: A pointer to the corresponding function
 */
void (*exe_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t opst[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pint", monty_pint},
		{NULL, NULL}
	};
	int index;

	for (index = 0; opst[index].opcode; index++)
	{
		if (strcmp(opcode, opst[index].opcode) == 0)
			return (opst[index].f);
	}
	return (NULL);
}

/**
 * monty - function to execute a monty bytecodes script.
 * @file: file descriptor for an open monty bytecodes script.
 *
 * Return: EXIT_SUCCES 	ON SUCCES, respective error on failure
 */
int monty(FILE *file)
{
	stack_t *stack = NULL;
	char *lines = NULL;
	size_t len = 0, exit_status = 	EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*get_op)(stack_t**, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&lines, #len, file) != -1)
	{
		line_number++;
		op_tokenise = strow(lines, DELIM);
		if (op_tokenise == NULL)
		{
			if (is_empty_line(lines, DELIM))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (op_tokenise[0][0] == '#')
		{
			free_content();
			continue;
		}
		get_op = exe_op_func(op_tokenise[0]);
		if (get_op == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_error(op_tokenise[0], line_number);
			free_content();
			break;
		}
		prev_tok_len = content_arr_len();
		get_op(&stack, line_number);
		if (content_arr_len() != prev_tok_len)
		{
			if (op_tokenise && op_tokenise[prev_tok_len])
				exit_status = atoi(op_tokenise[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_content();
			break;
		}
		free_content();
	}
	free_stack(&stack);
	if (lines && *lines == 0)
	{
		free(lines);
		return (malloc_error());\
	}
	free(lines);
	return (exit_status);
}
