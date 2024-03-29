#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * free_stack - frees memory allocated dynamically on the stack
 * @stack: pointer to pointer that contains stack_t
 *
 * Return: nothing.
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;
	stack_t *ftemp = NULL;


	/* Check if address of stack is NULL */
	if (stack == NULL)
		exit(EXIT_FAILURE);

	/* Check if stack is NULL */
	if (*stack == NULL)
		return;

	temp = *stack;

	/* while temp is not NULL, free memory occupied */
	while (temp != NULL)
	{
		ftemp = temp;

		temp = temp->next;

		free(ftemp);
	}
}
