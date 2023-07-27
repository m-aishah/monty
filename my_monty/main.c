#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **all_op_tokens = NULL;

/**
 * main - Entry point
 * @ac: The number of arguments used to execute the program
 * @av: An array of strings (arguments used to run the program)
 *
 * Return: 0, on success.
 */

int main(int ac, char **av)
{
	FILE *file_pathname = NULL;
	int exit_status = EXIT_SUCCESS;

	if (ac != 2)
		return (usage_error());
	file_pathname = fopen(av[1], "r");
	if (file_pathname == NULL)
		return (file_open_error(av[1]));
	exit_status = run_monty(file_pathname);
	fclose(file_pathname);
	return (exit_status);
}
