#include "monty.h"


/**
 * pchar - Prints the a character from its ascii equivalent
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int asci;
	char to_char;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	asci = (*stack)->n;
	if (asci < 33 || asci > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	to_char = (char)asci;
	printf("%c\n", to_char);
}

/**
 * pstr - Prints the a string from its ascii equivalent
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;

	ptr = *stack;
	while (ptr)
	{
		if (ptr->n <= 0 || ptr->n > 126)
			break;

		printf("%c", (char)ptr->n);
		ptr = ptr->next;
	}

	printf("\n");
}

/**
 * rot1 - Prints the a string from its ascii equivalent
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void rot1(stack_t **stack, unsigned int line_number)
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
	(*stack)->prev = last;
	*stack = (*stack)->next;

	(*stack)->prev = NULL;
	last->next->next = NULL;
}

/**
 * rotr - Rotates the stack to the bottom
 * (The last element of the stack become the top element)
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
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
