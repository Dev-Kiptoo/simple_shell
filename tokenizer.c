#include "shell.h"

/**
 * **strtow - string splitting into words.
 * @strw: the input string
 * @cc: the delimeter
 *
 * Return: array of string pointers
 */

char **strtow(char *strw, char *cc)
{
	int a, b, c, d, numwords = 0;
	char **ss;

	if (strw == NULL || strw[0] == 0)
		return (NULL);
	if (!cc)
		cc = " ";
	for (a = 0; strw[a] != '\0'; a++)
		if (!is_delim(strw[a], cc) && (is_delim(strw[a + 1], cc) || !strw[a + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	ss = malloc((1 + numwords) * sizeof(char *));
	if (!ss)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
		while (is_delim(strw[a], cc))
			a++;
		c = 0;
		while (!is_delim(strw[a + c], cc) && strw[a + c])
			c++;
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			for (c = 0; c < b; c++)
				free(s[c]);
			free(ss);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			s[b][d] = str[a++];
		s[b][d] = 0;
	}
	s[b] = NULL;
	return (ss);
}

/**
 * **strtow2 - string splitting into words
 * @str: e input string
 * @cc: e delimeter
 * Return: array of strings pointers
 */
char **strtow2(char *str, char cc)
{
	int a, b, c, d, numwords = 0;
	char **ss;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != cc && str[a + 1] == cc) ||
		    (str[a] != cc && !str[a + 1]) || str[a + 1] == cc)
			numwords++;
	if (numwords == 0)
		return (NULL);
	ss = malloc((1 + numwords) * sizeof(char *));
	if (!ss)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
		while (str[a] == cc && str[a] != cc)
			a++;
		c = 0;
		while (str[a + c] != cc && str[a + c] && str[a + c] != cc)
			c++;
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			for (c = 0; c < b; c++)
				free(ss[c]);
			free(ss);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			s[b][d] = str[a++];
		s[b][d] = 0;
	}
	s[b] = NULL;
	return (ss);
}
