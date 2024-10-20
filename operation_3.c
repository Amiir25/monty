#include "monty.h"

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
 * comment - Treats comments (doesn't do anything)
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void comment(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
