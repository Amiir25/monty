#include "monty.h"


/**
 * mul - Multiplies the second top value by the top value of the stack
 * @head: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void mul(stack_t **head, int line_number)
{
	stack_t *ptr;
	stack_t *node1;
	stack_t *node2;
	int count;

	ptr = *head;
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

	node1 = *head;
	node2 = node1->next;
	node2->n = node1->n * node2->n;
	node2->prev = NULL;
	*head = node2;
	free(node1);
}

/**
 * mod - Computes the rest of the division the second top value by the top value of the stack
 * @head: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void mod(stack_t **head, int line_number)
{
	stack_t *ptr;
	stack_t *node1;
	stack_t *node2;
	int count;

	ptr = *head;
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

	node1 = *head;
	node2 = node1->next;
	if (node2->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	node2->n = node2->n % node1->n;
	node2->prev = NULL;
	*head = node2;
	free(node1);
}
