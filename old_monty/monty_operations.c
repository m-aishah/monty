#include "monty.h"

void push_to_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *newNode;

    if (all_Op_Tokens[1] == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, all_Op_Tokens[0]);
        execFunc_exitStatus = EXIT_FAILURE;
        return;
    }

    newNode = malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        execFunc_exitStatus = EXIT_FAILURE;
        return;
    }
    if (is_valid_int(all_Op_Tokens[1]) == 0)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, all_Op_Tokens[0]);
        execFunc_exitStatus = EXIT_FAILURE;
        return;
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
    execFunc_exitStatus = EXIT_SUCCESS;
    printf("Push successful\n");
    return;

} /* check line 21*/

/**
 * is_valid_int: Function to check if a string can be made into a valid integer.
 * @value: The string in question.
 * Return: 1, if it can be a valid integer
 *              else, 0.
 */
int is_valid_int(char *value)
{
    int i;

    for (i = 0; value[i]; i++)
    {
        if (i == 0 && value[i] == '-')
            continue;
        if (value[i] < '0' || value[i] > '9')
            return (0);
    }
    return (1);
}

void print_all_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = (*stack);

    (void)line_number;

    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->prev;
    }
}