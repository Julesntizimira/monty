# include "monty.h"
/**
 * _free - free memory
 * @cmds: 2d array
 */
void _free(char **cmds)
{
	int i = 0;

	if (cmds == NULL)
		return;
	while (cmds[i] != NULL)
	{
		free(cmds[i]);
		i++;
	}
	free(cmds);
}
