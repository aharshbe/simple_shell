#include "ss_head.h"
/**
 * check_builtins - checks for builtins
 * @input: the input line recieved
 *
 * Return: either 1 or 0, 0 for success
 */

int check_builtins(sll *head)
{
	if (head == NULL)
	{
		if (isatty(0))
			write(1, "\n", 1);
		_sexit();
	}
	else if (_strcmp(head->str, "exit") == 0 || _strcmp(head->str, "quit") == 0)
	{
		_sexit();
	}
	else if (_strcmp(head->str, "history") == 0 || _strcmp(head->str, "h") == 0)
	{
		_shistory(head->str, 0);
		return (0);
	}
	else if (_strcmp(head->str, "setenv") == 0)
	{
		_setenv(head->next->str, head->next->next->str);
		return (0);
	}
	else if (_strcmp(head->str, "clear") == 0)
	{
		_sclear();
		return (0);
	}
	else if (_strcmp(head->str, "env") == 0)
	{
		print_env();
		return (0);
	}
	else if (_strcmp(head->str, "\n") == 0)
	{
		return (0);
	}
	else if (_strcmp(head->str, "cd") == 0)
	{
		_cd(head);
		return (0);
	}
	return (1);
}
