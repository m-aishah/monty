#include "monty.h"

void push_to_stack(stack_t **stack, unsigned int line_number)
{
    if (all_Op_Tokens[1] == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, all_Op_Tokens[0]);
        return (EXIT_FAILURE);
    }
    stack_t *newNode;

    newNode = malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        return (EXIT_FAILURE);
    }
    if (is_valid_int(all_Op_Tokens[1]) == 0)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, all_Op_Tokens[0]);
        return (EXIT_FAILURE);
    }
    newNode->n = atoi(all_Op_Tokens[1]);

    if ((*stack) == NULL)
    {
        newNode->prev = NULL;
        newNode->next = NULL;
        (*stack) = newNode;
    }
    else
    {
        newNode->prev = (*stack);
        newNode->next = NULL;
        (*stack) = newNode;
    }

} /* check line 21*/

void is_valid_int(char *value);