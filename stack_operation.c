#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

stack_t *stack = NULL;

/**
 * push - push an element inside a stack
 * @elem: element to push inside the stack
 *
 * Return: nothing
 */
void push(int elem)
{
	stack_t *new_node;
	stack_t *temp = stack;
	/* Allocate memory to new_node */
	new_node = malloc(sizeof(stack_t));
	/* Check if new_node return NULL */
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (temp == NULL)
	{
		new_node->n = elem;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		new_node->n = elem;
		new_node->prev = NULL;
		new_node->next = temp;

		temp->prev = new_node;
	}

	stack = new_node;
}
/**
 * pall - print all element inside a stack
 *
 * Return: nothing
 */
void pall(void)
{
	stack_t *temp = stack;
	if (temp == NULL)
		return;
	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - print the top-most element inside a stack
 * @line_num: line number of bytecode file
 *
 * Return: nothing
 */
void pint(unsigned int line_number)
{
	stack_t *temp = stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", temp->n);
}

/**
 * pop - pop the top-most element from the stack
 *
 * Return: nothing
 */

void pop(unsigned int line_number)
{
	stack_t *temp = stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack = stack->next;

	free(temp);
}

/**
 * swap - swap the top two elements of the stack
 *
 * Return: nothing
 */
/*
void swap(int elem)
{
}
*/
