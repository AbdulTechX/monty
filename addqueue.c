#include "monty.h"

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @stack: head of the stack
 * Return: no return
*/
void addqueue(stack_t **stack, int n)
{
	stack_t *new_node, *alt;

	alt = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (alt)
	{
		while (alt->next)
			alt = alt->next;
	}
	if (!alt)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		alt->next = new_node;
		new_node->prev = alt;
	}
}
