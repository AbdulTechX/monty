#include "monty.h"
/**
 * addnode - add node to the head stack
 * @stack: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **stack, int n)
{

	stack_t *new_node, *alt;

	alt = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (alt)
		alt->prev = new_node;
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
