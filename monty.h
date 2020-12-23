#ifndef MONTY
#define MONTY

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

extern int op_value;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int read_func(FILE *file_d);
int run(char *line, stack_t **stack, unsigned int line_number);
void add_int(stack_t **stack, unsigned int line_number);
void p_stack(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void print_error(unsigned int line_number, char *line_tok);
void p_error(unsigned int line_number);
void p_int(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
int checker(stack_t **stack, char *line_tok);
void nop(stack_t **stack, unsigned int line_number);
int loop(instruction_t *op_c, char *l_t, stack_t **s, unsigned int l_n);
void add_func(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

#endif
