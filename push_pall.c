#include "monty.h"

/**
 * is_number - Checks the argument of push
 * @str: The argument in string format
 *
 * Return: 1 if all characters are digit, 0 otherwise
 */

int is_number(char *str)
{
	if (str == NULL || *str == '\0')	/* Check for empty string */
		return (0);

	if (*str == '-' || *str == '+')	/* Handle - and + signd */
		str++;

	while (*str)
	{
		if (!isdigit(*str))		/* Check if each character is a digit */
			return (0);

		str++;
	}

	return (1);		/* Return true if all characters are digits */
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

	if (!is_number(arg))	/* Check if the arguement is a valid integer */
	{
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
		fprintf(stderr, "L%d: can't print, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}