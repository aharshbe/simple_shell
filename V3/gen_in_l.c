#include "ss_head.h"

/**
 * gen_ldkslfjds - generate an array of linked list pointers
 * @str: the string to be searched through
 * @delim: the delimeter
 *
 * Return: the head of the sll
 */
sll **gen_in_l(sll **input_list, char *s)
{
	int i, j;
	char *cur_str = s;
	int inp_len = _strlen(s);

	i = j = 0;

	/* check if this is just an 'enter' */
	if (_strcmp(s, "\n") == 0)
	{
		input_list[i] = gen_sll(s, " ");
		return (input_list);
	}


	while(s[i])
	{
		if (s[i] == '\n' || s[i] == ';')
		{
			/* !!! ; behavior should be different than \n */
			while (s[i] == '\n' || s[i] == ';')
			{
				s[i] = '\0';
				i++;
			}
			input_list[j++] = gen_sll(_strdup(cur_str), " ");
			cur_str = s + i;
		}
		/* !!! edgecase where && is at the very end */
		else if (s[i] == '&')
		{
			if (i < inp_len - 1)
				if (s[i + 1] == '&')
				{
					s[i] = '\0';
					s[i + 1] = '\0';
					i += 2;
					input_list[j++] = gen_sll(_strdup(cur_str), " ");
					cur_str = s + i;
				}
				else
					i++;
			else
				i++;
		}
		else
			i++;
	}
	input_list[j++] = gen_sll(_strdup(cur_str), " ");
	input_list[j] = NULL;

	return (input_list);
}

