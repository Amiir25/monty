#include "monty.h"

/**
 * pop - Remove the top element of the stack
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	*stack = ptr->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(ptr);
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	stack_t *node1;
	stack_t *node2;
	int count;

	ptr = *stack;
	count = 0;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node1 = *stack;
	node2 = node1->next;
	if (node2->next != NULL)
	{
		node1->next = node2->next;
		node1->prev = node2;
		node2->next->prev = node1;
		node2->next = node1;
		node2->prev = NULL;
	}

	else
	{
		node1->next = NULL;
		node1->prev = node2;
		node2->next = node1;
		node2->prev = NULL;
	}

	*stack = node2;
}

/**
 * add - Adds the value of the first two nodes
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	top->next->n += top->n;

	*stack = top->next;
	(*stack)->prev = NULL;
	free(top);
}

/**
 * nop - Doesn't do anything
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * sub - Subtracts the value of the first top node from the second one
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	top->next->n -= top->n;

	*stack = top->next;
	(*stack)->prev = NULL;
	free(top);
}
