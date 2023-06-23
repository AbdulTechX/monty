#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_tokenise = NULL;

/**
 * main - the entry point for Monty Interp
 *
 * @argc: the arguments passed to the program
 * @argv: pointer to an array of char pointers to argument
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
	FILE *file = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	file = fopen(argv[1], "r");
	if (file == NULL)
		return (f_open_error(argv[1]));
	exit_code = monty(file);
	fclose(file);
	return (exit_code);
}
