#include "monty.h"

/**
 * pop - Remove the top element of the stack
 * @head: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void pop(stack_t **head, int line_number)
{
	stack_t *ptr;

	if (is_empty(head))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	if (ptr->next != NULL)
	{
		*head = ptr->next;
		(*head)->prev = NULL;
		free(ptr);
	}

	else
	{
		*head = NULL;
		free(ptr);
	}
}
