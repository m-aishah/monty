#include "monty.h"

int run_monty(FILE *filepathName)
{
    char *lineContent = NULL;
    size_t n = 0;
    int char_Count = 0;
    int line_Count = 0;
    int token_Count = 0;
    char *optoken = NULL;
    char *all_Op_Tokens[1024] = NULL;

    while ((char_Count = getline(&lineContent, &n, filepathName)) != -1)
    {

        line_Count++;

        if (lineContent[count - 1] == '\n')
            lineContent[count - 1] = '\0';

        optoken = strtok(lineContent, " \t");
        while (optoken != NULL)
        {
            all_Op_Tokens[token_Count] = strdup(optoken);
            token_Count++;
            optoken = strtok(NULL, " \t");
        }
        if (execute_Opcode(all_Op_Tokens, line_Count) == EXIT_FAILURE)
        {
            free_Opcode(all_Op_Tokens, token_Count);
            free(lineContent);
            return (EXIT_FAILURE);
        }
        free_Opcode(all_Op_Tokens, token_Count);
        free(lineContent);
    }
    if (line_Count == 0)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

void free_Opcode(char *all_Op_Tokens[], int token_Count)
{
    int i = 0;
    for (; i < token_Count; i++)
        free(all_Op_Tokens[i]);
}

int execute_Opcode(char *all_Op_Tokens[], int line_Count)