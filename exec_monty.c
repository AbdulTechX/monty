#include "monty.h"


/**
* execute - executes the opcode
* @stack: head linked list - stack
* @line_number: line_counter
* @file: poiner to monty file
* @operation: line content
* Return: no return
*/
int execute(char *operation, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push},
				{"pall", f_pall},
				{"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(operation, " \n\t");
	if (op && op[0] == '#')
		return (0);
	monty.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(file);
		free(operation);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
