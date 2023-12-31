#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DELIMS " \n\t"

extern char **all_op_tokens;

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

/* Stack set-up functions */
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

int run_monty(FILE *file_pathname);

/* Helper functions. */
void free_op_tokens(void);
unsigned int token_arr_len(void);

char **strtow(char *str, char *delims);
char *change_int_str(int n);

/*Opcodes*/
void push_to_stack(stack_t **stack, unsigned int line_number);
void print_all_stack(stack_t **stack, unsigned int line_number);
void print_top_stack(stack_t **stack, unsigned int line_number);
void pop_from_stack(stack_t **stack, unsigned int line_number);
void swap_top_two(stack_t **stack, unsigned int line_number);
void add_top_two(stack_t **stack, unsigned int line_number);
void do_nothing(stack_t **stack, unsigned int line_number);
void sub_top_two(stack_t **stack, unsigned int line_number);
void div_top_two(stack_t **stack, unsigned int line_number);
void mul_top_two(stack_t **stack, unsigned int line_number);
void mod_top_two(stack_t **stack, unsigned int line_number);
void print_top_char(stack_t **stack, unsigned int line_number);
void print_top_str(stack_t **stack, unsigned int line_number);
void rotate_to_top(stack_t **stack, unsigned int line_number);
void rotate_to_bottom(stack_t **stack, unsigned int line_number);
void stack_mode(stack_t **stack, unsigned int line_number);
void queue_mode(stack_t **stack, unsigned int line_number);

/*Error functions*/
void set_op_tok_error(int exit_status);

int usage_error(void);
int malloc_error(void);
int file_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int swap_error(unsigned int line_number);
int add_error(unsigned int line_number);
int short_stack_errors(unsigned int line_number, char *error);
int div_error(unsigned int line_number);
int pchar_error_one(unsigned int line_number);
int pchar_error_two(unsigned int line_number);

#endif
