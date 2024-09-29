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
	stack_t *stack;
	stack_t *ptr;
	char *line;
	size_t len;
	char *opcode;
	char *arg;
	unsigned int line_number;

	stack = NULL;
	line = NULL;
	len = 0;
	line_number = 0;	/* Track the line number for error message */

	while (getline(&line, &len, file) != -1)	/* Read a line from the file */
	{

		line_number++;

		opcode = strtok(line, " \n\t\r");		/* Extract the first word */
		if (opcode == NULL || opcode[0] == '#')		/* Check if it is empty or comment */
			continue;

		arg = strtok(NULL, " \n\t\r");		
		process_opcode(&stack, opcode, line_number, arg);
	}

	free(line);
	while (stack != NULL)
	{
		ptr = stack;
		stack = stack->next;
		free(ptr);
	}
}

/**
 * process_opcode - Checks for valid opcode
 * @stack: The address of the pointer to the first node
 * @opcode: The opcode read by strtok() function
 * @line_number: The line number in the file
 * @arg: Thea argument of the opcode
 *
 * Return: Nothing
 */

void process_opcode(stack_t **stack, char *opcode, unsigned int line_number, char *arg)
{
	int i;

	instruction_t opcode_list[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {NULL, NULL}
	};

	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number, arg);
		return;
	}


	for (i = 0; opcode_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcode_list[i].opcode) == 0)
		{

			opcode_list[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
