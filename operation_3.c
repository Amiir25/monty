#include "monty.h"


/**
 * mul - Multiplies the second top value by the top value of the stack
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void mul(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node1 = *stack;
	node2 = node1->next;
	node2->n = node1->n * node2->n;
	node2->prev = NULL;
	*stack = node2;
	free(node1);
}

/**
 * mod - Computes the rest of the division of the second top value by
 * the top value of the stack
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void mod(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node1 = *stack;
	node2 = node1->next;
	if (node2->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	node2->n = node2->n % node1->n;
	node2->prev = NULL;
	*stack = node2;
	free(node1);
}

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
	char to_char;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	while (ptr)
	{
		if (ptr->n < 33 || ptr->n > 126)
			break;

		to_char = (char)ptr->n;
		ptr = ptr->next;
		printf("%c", to_char);
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
