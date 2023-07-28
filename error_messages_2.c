#include "monty.h"

/**
 * pint_error - prints the error message for can't pint, stack empty
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */

int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
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
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
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
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * add_error - prints the error message for stack too short to add
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int add_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_errors - prints the error message for different functions
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @error: error message to be printed
 * Return: (EXIT_FAILURE) always.
 */
int short_stack_errors(unsigned int line_number, char *error)
{
	fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, error);
	return (EXIT_FAILURE);
}
