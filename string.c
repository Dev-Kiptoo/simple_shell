#include "shell.h"

/**
 * _strlen - a fxt returning the length of a string
 * @ss: string whose length is to be checked
 *
 * Return: int(length of a string)
 */
int _strlen(char *ss)
{
	int k = 0;

	if (!ss)
		return (0);

	while (*ss++)
		k++;
	return (k);
}

/**
 * _strcmp - lexicogarphic comparison function.
 * @s1: the 1st string
 * @s2: the 2nd string
 *
 * Return: -ve if s1 < s2, +ve if s1 > s2, 0 if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - confirms if needle starts with haystack
 * @haystack: string to be searched
 * @needle: substring to be found
 *
 * Return: address of next haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - combining two strings
 * @dest: destination
 * @src: the source
 *
 * Return: destination pointer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
