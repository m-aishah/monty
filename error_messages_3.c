#include "monty.h"

/**
 * div_error - prints the error message for top stack equal to 0
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int div_error(unsigned int line_number)
{
    fprintf(stderr, "L%d: division by zero\n", line_number);
    return (EXIT_FAILURE);
}

/**
 * pchar_error_two - prints the error message for empty stack
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pchar_error_one(unsigned int line_number)
{
    fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
    return (EXIT_FAILURE);
}

/**
 * pchar_error_one - prints the error message for out of range ASCII characters
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pchar_error_two(unsigned int line_number)
{
    fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
    return (EXIT_FAILURE);
}
