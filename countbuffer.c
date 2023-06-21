# include "monty.h"
/**
 * countbuff - function to counts number of words in buffer
 * @buff: input buff
 * Return: number of words
 */
int countbuff(char *buff)
{
	int count = 0, i = 0;

	while (buff[i] != '\0')
	{
		if (buff[i] != ' ' && buff[i] != '\t')
		{
			count++;
			while (buff[i] != ' ' && buff[i] != '\t' && buff[i] != '\0')
				i++;
			continue;
		}
		i++;
	}
	return (count);
}
