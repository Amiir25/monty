#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function of monty.c */
void read_file(FILE *);
void get_opcode(stack_t **, char *, int);

/* Functions of operation-1.c */
void push(stack_t **, int, char *);
void pall(stack_t **);
void pint(stack_t **, int);
int is_number(char *);
int is_empty(stack_t **);

/* Functions of operation-2.c */
void pop(stack_t **, int);
void swap(stack_t **, int);
void add(stack_t **, int);
void sub(stack_t **, int);
void _div(stack_t **, int);

/* Functions of operation-3.c */
void mul(stack_t **, int);

#endif /* MONTY_H */
