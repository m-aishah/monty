#define _POSIX_C_SOURCE 200809L

#include "monty.h"
#include <stdio.h>
#include <string.h>

char **all_Op_Tokens = NULL;
int execFunc_exitStatus = EXIT_SUCCESS;

/**
 * run_monty: Function to run the bytecodes on each line
 * @filepathName: Path of the file containing bytecodes
 * Return: exit status of the operation -
 * EXIT_SUCCESS on success and EXIT_FAILURE on failure.
 */

int run_monty(FILE *filepathName)
{
	int i;
	stack_t *stack = NULL;
    size_t n = 0;
    int char_Count = 0;
    unsigned int line_number = 0;
    int token_Count = 0;
    int exit_status = EXIT_SUCCESS;
    char *optoken = NULL;
    char *lineContent = NULL;

	 all_Op_Tokens = malloc(1024 * sizeof(char *));
    stack = malloc(sizeof(stack_t));
    if (stack == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        return (EXIT_FAILURE);
    }

	stack->next = NULL;
	stack->prev = NULL;
    while ((char_Count = getline(&lineContent, &n, filepathName)) != -1)
    {

        line_number++;

        if (lineContent[char_Count - 1] == '\n')
            lineContent[char_Count - 1] = '\0';

		printf("%s\n", lineContent);
		optoken = strtok(lineContent, " \t");
		 while (optoken != NULL)
        {

            all_Op_Tokens[token_Count] = strdup(optoken);
            optoken = strtok(NULL, " \t");
            token_Count++;
			printf("%d\n", token_Count);
        }
        all_Op_Tokens[token_Count] = NULL;
		if (execute_Opcode(&stack, line_number) == EXIT_FAILURE)
        {
            for (i = 0; i < token_Count; i++)
				free(all_Op_Tokens[i]);
			free(lineContent);
            exit_status = EXIT_FAILURE;
            break;
        }
	}
	free_stack(&stack);
	free(stack);
	for (i = 0; i < token_Count; i++)
		free(all_Op_Tokens[i]);
	free(lineContent);
	free(all_Op_Tokens);
	return (0);
}






/**
 * @execute_Opcode - Function to execute the bytecode on a line.
 * @all_Op_Tokens - Array of tokens
 * @line_Count - The line that is currently being executed
 * Return: exit status of the operation -
 * EXIT_SUCCESS on success and EXIT_FAILURE on failure.
 */
int execute_Opcode(stack_t **stack, unsigned int line_number)
{
    int i;

    instruction_t get_Op_Function[] = {
        {"push", push_to_stack},
        {"pall", print_all_stack},
        {NULL, NULL}};
 for (i = 0; i < 3; i++)
    {
        if (strcmp(all_Op_Tokens[0], get_Op_Function[i].opcode) == 0)
        {
            printf("It's a match\n");
			get_Op_Function[i].f(stack, line_number);
			break;
        }
    }
    if (i == 3)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, all_Op_Tokens[0]);
        return (EXIT_FAILURE);
    }
    return (execFunc_exitStatus);
}


/**
 * free_stack - Function to free a stack
 * @stack - Address of stack to be freed
 */
void free_stack(stack_t **stack)
{
    stack_t *tmp;
	tmp = *stack;

    while (tmp)
    {
        (*stack) = (*stack)->prev;
        free(tmp);
        tmp = (*stack);
    }
}
