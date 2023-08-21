#include "shell.h"

/**
 * _strcpy - string copying
 * @dest: destiny
 * @src: source/origin
 *
 * Return: pointer to destiny string
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = 0;
	return (dest);
}

/**
 * _strdup - string duplication
 * @std: duplicated string
 *
 * Return: duplicated string pointer
 */
char *_strdup(const char *std)
{
	int len = 0;
	char *ret;

	if (std == NULL)
		return (NULL);
	while (*std++)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	for (len++; len--;)
		ret[len] = *--std;
	return (ret);
}

/**
 *_puts - input string printing
 *@stp: printed string
 *
 * Return: Null
 */
void _puts(char *stp)
{
	int a = 0;

	if (!stp)
		return;
	while (stp[a] != '\0')
	{
		_putchar(stp[a]);
		a++;
	}
}

/**
 * _putchar - character c to stdout writing
 * @c: The character to print
 *
 * Return: On success 1.
 */
int _putchar(char c)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(1, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}
