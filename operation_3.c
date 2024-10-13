#include "monty.h"


/**
 * _div - Divides the second top value by the top value of the stack
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	top->next->n /= top->n;
	*stack = top->next;
	(*stack)->prev = NULL;
	free(top);
}

/**
 * mul - Multiplies the second top value by the top value of the stack
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	top->next->n *= top->n;
	*stack = top->next;
	(*stack)->prev = NULL;
	free(top);
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
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	top->next->n %= top->n;
	*stack = top->next;
	(*stack)->prev = NULL;
	free(top);
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
