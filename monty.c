#include "monty.h"

/**
 * main - Entry
 * @ac: The number of arguments
 * @av: Array of arguments
 *
 * Return: Always success
 */

int main(int ac, char *av[])
{
	FILE *file;

	if (ac != 2)	/* Check if the file name is found in the arguement */
	{
		printf("Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");	/* Open the file to read */
	if (file == NULL)
	{
		printf("Error: can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	read_file(file);
	fclose(file);
	return (0);
}

/**
 * read_file - Reads a file
 * @file: A pointer to the file
 *
 * Return: Nothing
 */

void read_file(FILE *file)
{
	stack_t *head;
	stack_t *ptr;
	char *line;
	size_t len;
	char *opcode;
	int line_number;

	head = NULL;
	line = NULL;
	len = 0;
	line_number = 0;	/* Track the line number for error message */

	while (getline(&line, &len, file) != -1)	/* Read a line from the file */
	{

		line_number++;

		check_opcode1(&head, line, line_number);
		check_opcode2(&head, line, line_number);
		opcode = check_opcode3(&head, line, line_number);

		if (opcode != NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	while (head != NULL)
	{
		ptr = head;
		head = head->next;
		free(ptr);
	}
}

/**
 * check_opcode1 - Checks for valid opcode
 * @head: The address of the pointer to the first node
 * @line: The token returned by getline function
 * @line_number: The line number in the file
 *
 * Return: 1 for success, 0 for fail
 */

void check_opcode1(stack_t **head, char *line, int line_number)
{
	char *opcode;
	char *arg;

	opcode = strtok(line, " \n\t\r");		/* Extract the first word */
	if (opcode == NULL || opcode[0] == '#')		/* Check if it is empty or comment */
		return;
	if (strcmp(opcode, "push") == 0)
	{
		printf("Calling push\n");
		arg = strtok(NULL, " \n\t\r");
		push(head, line_number, arg);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(head);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		printf("Calling pint\n");
		pint(head, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(head, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(head, line_number);
	}

}

/**
 * check_opcode2 - Checks for valid opcode
 * @head: The address of the pointer to the first node
 * @line: The token returned by getline function
 * @line_number: The line number in the file
 *
 * Return: 1 for success, 0 for fail
 */

void check_opcode2(stack_t **head, char *line, int line_number)
{
	char *opcode;

	opcode = strtok(line, " \n\t\r");		/* Extract the first word */
	if (opcode == NULL || opcode[0] == '#')		/* Check if it is empty or comment */
		return;
	else if (strcmp(opcode, "add") == 0)
	{
		add(head, line_number);
	}
	else if (strcmp(opcode, "sub") == 0)
	{
		sub(head, line_number);

	}
	else if (strcmp(opcode, "div") == 0)
	{
		_div(head, line_number);
	}
	else if (strcmp(opcode, "mul") == 0)
	{
		mul(head, line_number);
	}
	else if (strcmp(opcode, "mod") == 0)
	{
		mod(head, line_number);
	}

}

/**
 * check_opcode3 - Checks for valid opcode
 * @head: The address of the pointer to the first node
 * @line: The token returned by getline function
 * @line_number: The line number in the file
 *
 * Return: 1 for success, 0 for fail
 */

char *check_opcode3(stack_t **head, char *line, int line_number)
{
	char *opcode;

	opcode = strtok(line, " \n\t\r");		/* Extract the first word */
	if (opcode == NULL || opcode[0] == '#')		/* Check if it is empty or comment */
		return (NULL);

	else if (strcmp(opcode, "pchar") == 0)
	{
		pchar(head, line_number);
		return (NULL);
	}

	else if (strcmp(opcode, "pstr") == 0)
	{
		pstr(head, line_number);
		return (NULL);
	}
	else if (strcmp(opcode, "rot1") == 0)
	{
		rot1(head);
		return (NULL);
	}
	else if (strcmp(opcode, "rotr") == 0)
	{
		rotr(head);
		return (NULL);
	}

	return (opcode);
}
