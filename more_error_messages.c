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

/**
 * swap_error - prints the error message for stack too short to swap
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */

int swap_error(unsigned int line_number)
{
    printf("L%d: can't swap, stack too short\n", line_number);
    return (EXIT_FAILURE);
}
<<<<<<< HEAD

/**
 * add_error - prints the error message for stack too short to add
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int add_error(unsigned int line_number)
{
    printf("L%d: can't add, stack too short\n", line_number);
    return (EXIT_FAILURE);
}
=======
>>>>>>> 04b5f437903b8aa156fcdd543a0f4e26b0740a52
