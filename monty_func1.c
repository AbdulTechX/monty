#include "monty.h"

void f_push(stack_t **stack, unsigned int line_number);
void f_pall(stack_t **stack, unsigned int line_number);
void f_pint(stack_t **stack, unsigned int line_number);
void f_pop(stack_t **stack, unsigned int line_number);

/**
 * f_push - add node to the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_push(stack_t **stack, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (monty.arg)
	{
		if (monty.arg[0] == '-')
			j++;
		for (; monty.arg[j] != '\0'; j++)
		{
			if (monty.arg[j] > 57 || monty.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(monty.monty_file);
			free(monty.op);
			free_stack(*stack);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(monty.monty_file);
		free(monty.op);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	n = atoi(monty.arg);
	if (monty.lifi == 0)
		addnode(stack, n);
	else
		addqueue(stack, n);
}

/**
 * f_pall - prints the stack
 * @stack: stack head
 * @line_number: no used
 * Return: no return
*/
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	(void)line_number;

	head = *stack;
	if (head == NULL)
		return;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * f_pint - prints the top
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(monty.monty_file);
		free(monty.op);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * f_pop - prints the top
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(monty.monty_file);
		free(monty.op);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	*stack = head->next;
	free(head);
}
