#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @stack: head of the stack
*/
void free_stack(stack_t *stack)
{
	stack_t *alt;

	alt = stack;
	while (stack)
	{
		alt = stack->next;
		free(stack);
		stack = alt;
	}
}
