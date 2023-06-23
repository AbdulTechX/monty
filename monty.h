#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIM " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_tokenise;

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

/* PRIMARY INTERPRETER FUNCTIONS */
void free_content(void);
unsigned int content_arr_len(void);
int is_empty_line(char *lines, char *delim);
int monty(FILE *file);
int init_stack(stack_t **stack);
void free_stack(stack_t **stack);
int check_mode(stack_t *stack);
void set_op_tok_error(int error_code);

/* OPERATION CODE FUNCTIONS */
void func_push(stack_t **stack, unsigned int line_number);
void func_pall(stack_t **stack, unsigned int line_number);
void func_pint(stack_t **stack, unsigned int line_number);
void func_pop(stack_t **stack, unsigned int line_number);
void func_swap(stack_t **stack, unsigned int line_number);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);
int getline();
/* ERROR MESSAGES & ERROR CODES */
int unknown_error(char *operation, unsigned int line_number);
int malloc_error(void);
int usage_error(void);
int no_int_error(unsigned int line_number);
int f_open_error(char *file);
int pint_error(unsigned int line_number);
#endif
