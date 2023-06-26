#include "monty.h"
/**
 * f_mul - multiplies the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_mul(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(monty.monty_file);
		free(monty.op);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	alt = head->next->n * head->n;
	head->next->n = alt;
	*stack = head->next;
	free(head);
}

/**
 * f_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_mod(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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
	alt = head->next->n % head->n;
	head->next->n = alt;
	*stack = head->next;
	free(head);
}
/**
 * f_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;
	if (!head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(monty.monty_file);
		free(monty.op);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (head->n > 127 || head->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(monty.monty_file);
		free(monty.op);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", head->n);
}
/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void f_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	(void)line_number;

	head = *stack;
	while (head)
	{
		if (head->n > 127 || head->n <= 0)
		{
			break;
		}
		printf("%c", head->n);
		head = head->next;
	}
	printf("\n");
}

#include "monty.h"
/**
  *f_rotl- rotates the stack to the top
  *@stack: stack head
  *@line_number: line_number
  *Return: no return
 */
void f_rotl(stack_t **stack,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack, *alt;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	alt = (*stack)->next;
	alt->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = alt;
}
