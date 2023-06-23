#include "monty.h"

/**
 * usage_error - prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int usage_error(void)
{
	fprintf(stderr, "USGAE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - file opening error
 * @file: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int f_open_error(char *file)
{
	fprintf(stderr, "Érror: Can't open file %s\n", file);
	return (EXIT_FAILURE);
}
