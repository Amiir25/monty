#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * main - Entry
 * @ac: The number of arguments
 * @av: Array of arguments
 *
 * Return: Always success
 */

int main(int ac, char **av)
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
	char *line;
	char *opcode;
	char *arg;
	size_t len;
	int line_number;
	stack_t *head;

	head = NULL;
	line = NULL;
	len = 0;
	line_number = 0;	/* Track the line number for error message */

	while (getline(&line, &len, file) != -1)	/* Read a line from the file */
	{
		line_number++;
		opcode = strtok(line, " \n\t\r");	/* Extract the first word */
		if (opcode == NULL || opcode[0] == '#')	/* Check if it is empty or comment */
			continue;

		if (strcmp(opcode, "push"))
		{
			arg = strtok(NULL, " \n\t\r");	/* Extract the argument of push */
			push(&head, line_number, arg);
		}
		else if (strcmp(opcode, "pall"))
			pall(&head);

		else	/* Unkown opcode error */
		{
			fprintf(stderr, "L%d Unkown instruction %s", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
}
