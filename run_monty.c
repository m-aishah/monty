#include "monty.h"

/**
 * run_monty: Function to run the bytecodes on each line
 * @filepathName: Path of the file containing bytecodes
 * Return: exit status of the operation -
 * EXIT_SUCCESS on success and EXIT_FAILURE on failure.
 */

int run_monty(FILE *filepathName)
{
    char *lineContent = NULL;
    size_t n = 0;
    int char_Count = 0;
    int line_number = 0;
    int token_Count = 0;
    char *optoken = NULL;
    char *all_Op_Tokens[1024] = NULL;

    while ((char_Count = getline(&lineContent, &n, filepathName)) != -1)
    {

        line_number++;

        if (lineContent[char_Count - 1] == '\n')
            lineContent[char_Count - 1] = '\0';

        optoken = strtok(lineContent, " \t");
        while (optoken != NULL)
        {
            all_Op_Tokens[token_Count] = strdup(optoken);
            token_Count++;
            optoken = strtok(NULL, " \t");
        }
        if (execute_Opcode(line_number) == EXIT_FAILURE)
        {
            free_Opcode(token_Count);
            free(lineContent);
            return (EXIT_FAILURE);
        }
        free_Opcode(token_Count);
        free(lineContent);
    }
    if (char_Count == -1 && errno == ENOMEM)
    {
        fprintf(stderr, "Error: malloc failed\n");
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

/**
 * free_Opcode - Function to free all tokens in array of tokens
 * @all_Op_Tokens - Array of tokens
 * @token_Count - Number of tokens to be freed
 */
void free_Opcode(int token_Count)
{
    int i = 0;
    for (; i < token_Count; i++)
        free(all_Op_Tokens[i]);
}

/**
 * @execute_Opcode - Function to execute the bytecode on a line.
 * @all_Op_Tokens - Array of tokens
 * @line_Count - The line that is currently being executed
 * Return: exit status of the operation -
 * EXIT_SUCCESS on success and EXIT_FAILURE on failure.
 */
int execute_Opcode(int line_number)
{
    int i;

    stack_t *stack;
    instruction_t get_Op_Function[] = {
        {"push", push_to_stack},
        {"pall", print_all_stack},
        {NULL, NULL}};

    for (i = 0; i < 3; i++)
    {
        if (strcmp(all_Op_Tokens[0], get_Op_Function[i].opcode) == 0)
        {
            get_Op_Function[i].f(&stack, line_number);
            break;
        }
    }
    if (i == 3)
    {
        fprintf(stderr, "L%d: unknown instruction %s", line_number, all_Op_Tokens[0]);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}