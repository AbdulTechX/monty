#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int len = 0, alt;

	head = *stack;
	while (head)
	{
		head = head->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(monty.monty_file);
		free(monty.op);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	alt = head->n;
	head->n = head->next->n;
	head->next->n = alt;
}

/**
 * f_add - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int len = 0, alt;

	head = *stack;
	while (head)
	{
		head = head->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(monty.monty_file);
		free(monty.op);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	alt = head->n + head->next->n;
	head->next->n = alt;
	*stack = head->next;
	free(head);
}
/**
  *f_nop- nothing
  *@stack: stack head
  *@line_number: line_number
  *Return: no return
 */
void f_nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
/**
  *f_sub- sustration
  *@stack: stack head
  *@line_number: line_number
  *Return: no return
 */
void f_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *alt;
	int sus, nodes;

	alt = *stack;
	for (nodes = 0; alt != NULL; nodes++)
		alt = alt->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(monty.monty_file);
		free(monty.op);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	alt = *stack;
	sus = alt->next->n - alt->n;
	alt->next->n = sus;
	*stack = alt->next;
	free(alt);
}

/**
 * f_div - divides the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_div(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int len = 0, alt;

	head = *stack;
	while (head)
	{
		head = head->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(monty.monty_file);
		free(monty.op);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(monty.monty_file);
		free(monty.op);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	alt = head->next->n / head->n;
	head->next->n = alt;
	*stack = head->next;
	free(head);
}
