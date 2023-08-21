#include "shell.h"

/**
 * is_chain - checks if the current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: buffer to the character
 * @pp: current position's address in buf
 *
 * Return: 1 if chain delimeter, 0 else
 */
int is_chain(info_t *info, char *buf, size_t *pp)
{
	size_t s = *pp;

	if (buf[s] == '|' && buf[s + 1] == '|')
	{
		buf[s] = 0;
		s++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[s] == '&' && buf[s + 1] == '&')
	{
		buf[s] = 0;
		s++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[s] == ';') /* found end of this command */
	{
		buf[s] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*pp = s;
	return (1);
}

/**
 * check_chain - checks if we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: buffer of the character
 * @pp: current position in buff*r
 * @ii: starting position in buff*r
 * @len: length of buff*r
 *
 * Return: Null
 */
void check_chain(info_t *info, char *buf, size_t *pp, size_t ii, size_t len)
{
	size_t s = *pp;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[ii] = 0;
			s = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[ii] = 0;
			s = len;
		}
	}

	*pp = s;
}

/**
 * replace_alias - alias replacement in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 elsewhere
 */
int replace_alias(info_t *info)
{
	int a;
	list_t *node;
	char *pp;

	for (a = 0; a < 10; a++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		pp = _strchr(node->str, '=');
		if (!pp)
			return (0);
		pp = _strdup(pp + 1);
		if (!pp)
			return (0);
		info->argv[0] = pp;
	}
	return (1);
}

/**
 * replace_vars - variable replacement in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 elsewhere
 */
int replace_vars(info_t *info)
{
	int a = 0;
	list_t *node;

	for (a = 0; info->argv[a]; a++)
	{
		if (info->argv[a][0] != '$' || !info->argv[a][1])
			continue;

		if (!_strcmp(info->argv[a], "$?"))
		{
			replace_string(&(info->argv[a]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[a], "$$"))
		{
			replace_string(&(info->argv[a]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[a][1], '=');
		if (node)
		{
			replace_string(&(info->argv[a]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[a], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - string replacement
 * @previous: string address
 * @current: new string
 *
 * Return: 1 if replaced, 0 elsewhere
 */
int replace_string(char **previous, char *current)
{
	free(*previous);
	*previous = current;
	return (1);
}
