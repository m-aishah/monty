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
	}
	
	free(stack);
	for (i = 0; i < token_Count; i++)
		free(all_Op_Tokens[i]);
	free(lineContent);
	free(all_Op_Tokens);
	return (0);
}




/**
 * free_Opcode - Function to free all tokens in array of tokens
 * @all_Op_Tokens - Array of tokens
 * @token_Count - Number of tokens to be freed

void free_Opcode(char *all_Op_Tokens, int token_Count)
{
    int i = 0;
    for (; i < token_Count; i++)
        free(all_Op_Tokens[i]);
}
*/
