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