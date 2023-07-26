#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

int run_monty(FILE *filepathName);
int free_Opcode(char *all_Op_Tokens[]);
int execute_Opcode(char *all_Op_Tokens[], int line_Count);

#endif