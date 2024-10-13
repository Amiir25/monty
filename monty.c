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
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");	/* Open the file to read */
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
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

	while (getline(&line, &len, file) != -1)
	{

		line_number++;

		opcode = strtok(line, " \n\t\r");
		if (opcode == NULL || opcode[0] == '#')
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
 * @arg: The argument of the opcode
 *
 * Return: Nothing
 */

void process_opcode(stack_t **stack, char *opcode,
		    unsigned int line_number, char *arg)
{
	int i;

	instruction_t opcode_list[] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"nop", nop}, {"sub", sub}, {"div", _div}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar}, {"pstr", pstr},
		{"rot1", rot1}, {"rotr", rotr}, {NULL, NULL}
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
