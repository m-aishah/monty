/**
 * pint_error - prints the error message for can't pint, stack empty
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */

int pint_error(int line_number)
{
    printf("L%d: can't pint, stack empty\n", line_number);
    return (EXIT_FAILURE);
}