#include "shell.h"

/**
 **_memset - memory filling with a constant byte
 *@ss: memory area pointer
 *@b: byte fillint *ss with
 *@n:the amount of bytes to be filled
 *Return: (*ss)
 */
char *_memset(char *ss, char b, unsigned int n)
{
	unsigned int k;

	for (k = 0; k < n; k++)
		ss[k] = b;
	return (ss);
}

/**
 * ffree - free strings
 * @pps: string of strings
 */
void ffree(char **pps)
{
	char **a = pps;

	if (!pps)
		return;
	while (*pps)
		free(*pps++);
	free(a);
}

/**
 * _realloc - block of memory realocation
 * @ptr: pointer to previous allocated block
 * @old_size: previous block byte size
 * @new_size: new block byte size
 *
 * Return: old block's pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pp;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	pp = malloc(new_size);
	if (!pp)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		pp[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (pp);
}
