#include "monty.h"

/**
 * push - add an element into the stack
 * @stack: where to push the element
 * @line_number: the line where push instruction is called from
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(struct stack_s));
	stack_t *temp;
	(void)line_number;
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	new_node->n = data;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	new_node->prev = temp;
	new_node->next = NULL;

	(*stack)->next = new_node;
	*stack = new_node;
}

/**
 * pall - print all element in the stack
 * @stack: where to print the elements from
 * @line_number: the line where pall instruction is called from
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;
	if (stack == NULL || *stack == NULL)
		return;

	temp = *stack;
	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->prev;
	}
}

/**
 * pint - print the top element in the stack
 * @stack: the stack
 * @line_number: the line where pint instruction is called from
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		return;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}
