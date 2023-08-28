#include "monty.h"

/**
 * free_stack - frees dynamically allocated memory
 * @stack: the stack pointer
 */

void free_stack(stack_t *stack)
{
	if (stack == NULL)
		exit(EXIT_SUCCESS);

	while (stack && stack->prev != NULL)
	{
		stack = stack->prev;
		free(stack->next);
	}
	free(stack);
}
