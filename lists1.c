#include "shell.h"

/**
 * list_len - shows the length of a linked list
 * @head: first node pointer
 *
 * Return: size of list
 */
size_t list_len(const list_t *head)
{
	size_t a = 0;

	while (head)
	{
		head = head->next;
		a++;
	}
	return (a);
}

/**
 * list_to_strings - a fxt ret strings of the list->str
 * @hptr: first node pointer
 *
 * Return: strings
 */
char **list_to_strings(list_t *hptr)
{
	list_t *node = hptr;
	size_t s = list_len(hptr), j;
	char **str1;
	char *str;

	if (!hptr || !s)
		return (NULL);
	str1 = malloc(sizeof(char *) * (s + 1));
	if (!str1)
		return (NULL);
	for (s = 0; node; node = node->next, s++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < s; j++)
				free(str1[j]);
			free(str1);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		str1[s] = str;
	}
	str1[s] = NULL;
	return (str1);
}


/**
 * print_list - printing elements of a list_t linked list
 * @hptr: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *hptr)
{
	size_t s = 0;

	while (hptr)
	{
		_puts(convert_number(hptr->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(hptr->str ? hptr->str : "(nil)");
		_puts("\n");
		hptr = hptr->next;
		s++;
	}
	return (s);
}

/**
 * node_starts_with - checks for a node starting with prefix
 * @node: list head pointer
 * @prefix: string to match
 * @cc: character after prefix to match
 *
 * Return: match node / null
 */
list_t *node_starts_with(list_t *node, char *prefix, char cc)
{
	char *pp = NULL;

	while (node)
	{
		pp = starts_with(node->str, prefix);
		if (pp && ((cc == -1) || (*pp == cc)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @hptr: first node pointer
 * @node: pointer to the node
 *
 * Return: index of node || -1
 */
ssize_t get_node_index(list_t *hptr, list_t *node)
{
	size_t s = 0;

	while (hptr)
	{
		if (hptr == node)
			return (s);
		hptr = hptr->next;
		s++;
	}
	return (-1);
}
