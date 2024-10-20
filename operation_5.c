#include "monty.h"

/**
 * stack_mode - Sets the format of the data to a stack(LIFO)
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	/* Set to stack mode */
	current_mode = 0;
}

/**
 * queue_mode - Sets the format of the data to a queue(FIFO)
 * @stack: The address of the pointer to the first node
 * @line_number: The line number in the file
 *
 * Return: Nothing
 */

void queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	/* Set to queue mode */
	current_mode = 1;
}
