#include "shell.h"

/**
 * main - the origin
 * @ab: argument count
 * @j: argument vector
 *
 * Return: upon sucess return 0, 1 on error
 */
int main(int ab, char **j)
{
	info_t info[] = { INFO_INIT };
	int ad = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (ad)
		: "r" (ad));

	if (ab == 2)
	{
		ad = open(j[1], O_RDONLY);
		if (ad == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(j[0]);
				_eputs(": 0: Can't open ");
				_eputs(j[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = ad;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, j);
	return (EXIT_SUCCESS);
}
