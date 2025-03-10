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

	ptr = *stack;
	while (ptr != NULL)
	{
		*stack = (*stack)->next;
		free(ptr);
		ptr = *stack;
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
 * pre_push - Creates a pointer to a new node
 * @stack: The address of the pointer to the first node
 * @line_number: The line number of an error in the file if occur
 * @arg: The argument of push
 *
 * Return: Nothing
 */

void pre_push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;

	if (arg == NULL || !is_number(arg))
	{
		free_stack(stack);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = NULL;

	push_stack_queue(stack, &new_node);
}

/**
 * push_stack_queue - Pushs a new node to a stack or queue based
 * on the value of the 'current_mode' variable.
 * @stack: The address of the pointer to the first node
 * @new_node: The address of the pointer to the new node
 *
 * Return: Nothing
 */

void push_stack_queue(stack_t **stack, stack_t **new_node)
{
	stack_t *ptr;

	/* Stack mode */
	if (current_mode == 0)
	{
		(*new_node)->next = *stack;

		if (*stack != NULL)
			(*stack)->prev = *new_node;

		*stack = *new_node;
	}

	/*Queue mode */
	else
	{
		if (*stack == NULL)
			*stack = *new_node;

		else
		{
			ptr = *stack;
			while (ptr->next != NULL)
				ptr = ptr->next;

			ptr->next = *new_node;
			(*new_node)->prev = ptr;
		}
	}
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
