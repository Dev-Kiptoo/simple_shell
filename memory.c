#include "shell.h"

/**
 * bfree - makes the address null and frees *ptr
 * @ptr: address of the null pointer
 *
 * Return: 1 once freed, else 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
