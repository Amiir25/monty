#include "monty.h"

/**
 * free_stack - Frees allocated memory
 * @stack: The address of the pointer to the first node
 *
 * Return: 1 if empty, 0 otherwise
 */

void free_stack(stack_t **stack)
{
	stack_t *ptr;

	while (ptr != NULL)
	{
		ptr = *stack;
		*stack = (*stack)->next;
		free(ptr);
	}
}

/**
 * is_number - Checks the argument of push
 * @str: The argument in string format
 *
 * Return: 1 if all characters are digit, 0 otherwise
 */

int is_number(char *str)
{
	if (str == NULL)
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	if (*str == '\0')
		return (0);

	while (*str)
	{
		if (!isdigit(*str))
			return (0);

		str++;
	}

	return (1);
}

/**
 * push - Inserts a new node to the stack
 * @stack: The address of the pointer to the first node
 * @line_number: The line number of an error in the file if occur
 * @arg: The argument of push
 *
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;

	if (arg == NULL || !is_number(arg))
	{
		free_stack(stack);
		fprintf(stderr, "L%d: Usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - Prints all the elements in the stack
 * @stack: The address of the pointer to the first node
 * @line_number: The line number of an error in the file if occur
 *
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;

	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
