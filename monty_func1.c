#include "monty.h"


/**
 * func_push - Push the value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void func_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp_node, *new_node;
	int index;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_tokenise[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}

	for (index = 0; op_tokenise[1][index]; index++)
	{
		if (op_tokenise[1][index] == '-' && index == 0)
			continue;
		if (op_tokenise[1][index] < '0' || op_tokenise[1][index] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	new_node->n = atoi(op_tokenise[1]);

	if (check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp_node = (*stack)->next;
		new_node->prev = *stack;
		new_node->next = tmp_node;
		if (tmp_node)
			tmp_node->prev = new_node;
		(*stack)->next = new_node;
	}
	else /* QUEUE mode insert at end */
	{
		tmp_node = *stack;
		while (tmp_node->next)
			tmp_node = tmp_node->next;
		new_node->prev = tmp_node;
		new_node->next = NULL;
		tmp_node->next = new_node;
	}
}
/**
 * func_pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void func_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp_node = (*stack)->next;

	while (tmp_node)
	{
		printf("%d\n", tmp_node->n);
		tmp_node = tmp_node->next;
	}
	(void)line_number;
}
/**
 * func_pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void func_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}
/**
 * func_pop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void func_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * func_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void func_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp_node;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	tmp_node = (*stack)->next->next;
	(*stack)->next->next = tmp_node->next;
	(*stack)->next->prev = tmp_node;
	if (tmp_node->next)
		tmp_node->next->prev = (*stack)->next;
	tmp_node->next = (*stack)->next;
	tmp_node->prev = *stack;
	(*stack)->next = tmp_node;
}
