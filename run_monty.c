#define _POSIX_C_SOURCE 200809L

#include "monty.h"
#include <string.h>

void free_op_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_function(char *opcode))(stack_t **, unsigned int);
int run_monty(FILE *file_pathname);

/**
 * free_op_tokens - Function to free all tokens in array of tokens.
 */
void free_op_tokens(void)
{
    size_t i = 0;

    if (all_op_tokens == NULL)
        return;

    for (i = 0; all_op_tokens[i]; i++)
        free(all_op_tokens[i]);

    free(all_op_tokens);
}

/**
 * token_arr_len - Gets the length of all_op_tokens.
 *
 * Return: Length of current all_op_tokens.
 */

unsigned int token_arr_len(void)
{
    unsigned int toks_len = 0;

    while (all_op_tokens[toks_len])
        toks_len++;
    return (toks_len);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
    int i, j;

    for (i = 0; line[i]; i++)
    {
        for (j = 0; delims[j]; j++)
        {
            if (line[i] == delims[j])
                break;
        }
        if (delims[j] == '\0')
            return (0);
    }

    return (1);
}

/**
 * get_op_function - Function to match an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_function(char *opcode))(stack_t **, unsigned int)
{
    instruction_t op_and_funcs[] = {
        {"push", push_to_stack},
        {"pall", print_all_stack},
        {"pint", print_top_stack},
        {"pop", pop_from_stack},
        {"swap", swap_top_two},
        {NULL, NULL}};
    int i;

    for (i = 0; op_and_funcs[i].opcode; i++)
    {
        if (strcmp(opcode, op_and_funcs[i].opcode) == 0)
            return (op_and_funcs[i].f);
    }

    return (NULL);
}

/**
 * run_monty - Function to run the bytecodes on each line
 * @file_pathname: Pathname of the file containing bytecodes
 *
 * Return: EXIT_SUCCESS on success,
 *		respective error code on failure.
 */
int run_monty(FILE *file_pathname)
{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0, exit_status = EXIT_SUCCESS;
    unsigned int line_number = 0, prev_tok_len = 0;
    void (*op_function)(stack_t **, unsigned int);

    if (init_stack(&stack) == EXIT_FAILURE)
        return (EXIT_FAILURE);

    while (getline(&line, &len, file_pathname) != -1)
    {
        line_number++;
        all_op_tokens = strtow(line, DELIMS);
        if (all_op_tokens == NULL)
        {
            if (is_empty_line(line, DELIMS))
                continue;
            free_stack(&stack);
            return (malloc_error());
        }
        else if (all_op_tokens[0][0] == '#')
        {
            free_op_tokens();
            continue;
        }
        op_function = get_op_function(all_op_tokens[0]);
        if (op_function == NULL)
        {
            free_stack(&stack);
            exit_status = unknown_op_error(all_op_tokens[0], line_number);
            free_op_tokens();
            break;
        }
        prev_tok_len = token_arr_len();
        op_function(&stack, line_number);
        if (token_arr_len() != prev_tok_len)
        {
            if (all_op_tokens && all_op_tokens[prev_tok_len])
                exit_status = atoi(all_op_tokens[prev_tok_len]);
            else
                exit_status = EXIT_FAILURE;
            free_op_tokens();
            break;
        }
        free_op_tokens();
    }
    free_stack(&stack);

    if (line && *line == 0)
    {
        free(line);
        return (malloc_error());
    }
    free(line);
    return (exit_status);
}
