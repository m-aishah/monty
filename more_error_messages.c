#include "monty.h"

/**
 * pint_error - prints the error message for can't pint, stack empty
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */

int pint_error(unsigned int line_number)
{
    printf("L%d: can't pint, stack empty\n", line_number);
    return (EXIT_FAILURE);
}

/**
 * pop_error - prints the error message for can't pop an empty stack
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */

int pop_error(unsigned int line_number)
{
    printf("L%d: can't pop an empty stack\n", line_number);
    return (EXIT_FAILURE);
}

int swap_error(unsigned int line_number)
{
    printf("L%d: can't swap, stack too short\n");
    return (EXIT_FAILURE);
}