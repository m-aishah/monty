#include "monty.h"

/**
 * main - Entry point
 * @ac: The number of arguments used to execute the program
 * @av: An array of strings (arguments used to run the program)
 *
 * Return: 0, on success.
 */

int main(int ac, char *av[])
{
    int exit_status;
    FILE *filepathName;

    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    filepathName = fopen(av[1], "r");
    if (filepathName == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s", av[1]);
        exit(EXIT_FAILURE);
    }

    exit_status = run_monty(filepathName);
    exit(exit_status);
}
