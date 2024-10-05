#include "monty.h"


/**
 * rotr - Rotates the stack to the bottom
 * (The last element of the stack become the top element)
 * @stack: The address of the pointer to the first node
 *
 * Return: Nothing
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	stack_t *last;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	while (ptr)
	{
		last = ptr;
		ptr = ptr->next;
	}

	last->next = *stack;
	last->prev->next = NULL;
	last->prev = NULL;

	(*stack)->prev = last;
	*stack = last;
}
