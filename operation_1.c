#include "monty.h"

/**
 * free_stack - Frees allocated memory
 * @head: The address of the pointer to the first node
 *
 * Return: 1 if empty, 0 otherwise
 */

void free_stack(stack_t **head)
{
	stack_t *ptr;

	while (ptr != NULL)
	{
		ptr = *head;
		*head = (*head)->next;
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
 * @head: The address of the pointer to the first node
 * @line_number: The line number of an error in the file if occur
 * @arg: The argument of push
 *
 * Return: Nothing
 */

void push(stack_t **head, int line_number, char *arg)
{
	stack_t *new_node;

	if (arg == NULL || !is_number(arg))
	{
		free_stack(head);
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
	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

/**
 * pall - Prints all the elements in the stack
 * @head: The address of the pointer to the first node
 *
 * Return: Nothing
 */

void pall(stack_t **head)
{
	stack_t *ptr;

	ptr = *head;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - Prints the value at the top of the stack
 * @head: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void pint(stack_t **head, int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
