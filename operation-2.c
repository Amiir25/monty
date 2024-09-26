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

/**
 * swap - Swaps the top two elements of the stack
 * @head: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void swap(stack_t **head, int line_number)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node1 = *head;
	node2 = node1->next;
	if (node2->next != NULL)
	{
		node1->next = node2->next;
		node1->prev = node2;
		node2->next->prev = node1;
		node2->next = node1;
		node2->prev = NULL;
	}

	else
	{
		node1->next = NULL;
		node1->prev = node2;
		node2->next = node1;
		node2->prev = NULL;
	}

	*head = node2;
}

/**
 * add - Adds the value of the first two nodes
 * @head: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void add(stack_t **head, int line_number)
{
	stack_t *ptr;
	stack_t *node1;
	stack_t *node2;
	int count;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	count = 0;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node1 = *head;
	node2 = node1->next;
	node2->n = node1->n + node2->n;
	node2->prev = NULL;
	*head = node2;
	free(node1);
}

/**
 * sub - Subtracts the value of the first top node from the second one
 * @head: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void sub(stack_t **head, int line_number)
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node1 = *head;
	node2 = node1->next;
	node2->n = node2->n - node1->n;
	node2->prev = NULL;
	*head = node2;
	free(node1);
}
