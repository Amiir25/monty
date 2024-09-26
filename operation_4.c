#include "monty.h"


/**
 * rotr - Rotates the stack to the bottom
 * (The last element of the stack become the top element)
 * @head: The address of the pointer to the first node
 *
 * Return: Nothing
 */

void rotr(stack_t **head)
{
	stack_t *ptr;
	stack_t *last;

	ptr = *head;
	while (ptr)
	{
		last = ptr;
		ptr = ptr->next;
	}

	last->next = *head;
	last->prev->next = NULL;
	last->prev = NULL;

	(*head)->prev = last;
	*head = last;
}
