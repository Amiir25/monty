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

/* A global variable to control the format of the data (stack vs queue) */
extern int current_mode;

/* Function of monty.c */
void read_file(FILE *);
void process_opcode(stack_t **, char *, unsigned int, char *);

/* Functions of operation-1.c */
void free_stack(stack_t **);
int is_number(char *);
void pre_push(stack_t **, unsigned int, char *);
void push_stack_queue(stack_t **, stack_t **);
void pall(stack_t **, unsigned int);

/* Functions of operation-2.c */
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);

/* Functions of operation-3.c */
void sub(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void comment(stack_t **, unsigned int);

/* Functions of operation_4.c */
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

/* Functions of operation_5.c */
void stack_mode(stack_t **, unsigned int);
void queue_mode(stack_t **, unsigned int);

#endif /* MONTY_H */
