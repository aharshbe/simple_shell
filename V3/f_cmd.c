#include "ss_head.h"

/**
* find_command - find shell commands PATH
* @command: commands name
* Return: PATH to command
*/

char *f_cmd(char *command)
{
	char *_paths = NULL, *full_path;
	int found = 0;
	char *_path = getenv("PATH");

	_paths = strtok(strdup(_path), ":");

	if (access(command, F_OK) == 0)
		return (command);

	while (_paths != NULL)
	{
		full_path = _strcat(_paths, command);
		if (access(full_path, F_OK) == 0)
		{
			found = 1;
			break;
		}
		_paths = strtok(NULL, ":");
	}
	if (!found)
		return (NULL);

	return(full_path);
}