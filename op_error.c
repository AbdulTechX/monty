#include "monty.h"

/**
 * set_op_tok_error - Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
	int toks_len = 0, i = 0;
	char *exit_string = NULL;
	char **new_tokenise = NULL;

	toks_len = content_arr_len();
	new_tokenise = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_tokenise)
	{
		malloc_error();
		return;
	}
	while (i < toks_len)
	{
		new_tokenise[i] = op_tokenise[i];
		i++;
	}
	exit_string = get_int(error_code);
	if (!exit_string)
	{
		free(new_tokenise);
		malloc_error();
		return;
	}
	new_tokenise[i++] = exit_string;
	new_tokenise[i] = NULL;
	free(op_tokenise);
	op_tokenise = new_tokenise;
}
