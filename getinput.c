# include "monty.h"
/**
 * _strcmp - compare strings
 * @str1: string1
 * @str2: string2
 * Return: 0 on success and -1 otherwise
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	if (_strlen(str1) != _strlen(str2))
		return (-1);

	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	return (0);
}
/**
 * _strlen - compute string length
 * @s: input string
 * Return: string length
 */
int _strlen(char *s)
{
	int len = 0;

	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}
/**
 * _strdup - duplicate string
 * @str: input string
 * Return: newly created string
 */
char *_strdup(char *str)
{
	int i = 0, len;
	char *buff = NULL;

	len = _strlen(str);
	buff = malloc((len + 1) * sizeof(char));

	if (buff == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (i < len)
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
/**
 * tokenise - tokenise string
 * @buff: input string
 * @delim: delimiter
 * Return: pointer to an array of strings
 */
char **tokenise(char *buff, char delim)
{
	char **cmds = NULL, token[1024] = {'\0'};
	int i = 0, j = 0, z = 0, count = 0;

	while (buff[i] != '\0')
	{
		if (buff[i] == delim)
			count++;
		i++;
	}
	count++;
	cmds = malloc(count * sizeof(char *));
	if (cmds == NULL)
	{
		free(buff);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == delim)
		{
			i++;
			continue;
		}
		while (buff[i] != delim)
		{
			token[j] = buff[i];
			j++;
			i++;
		}
		token[j] = '\0';
		cmds[z] = _strdup(token);
		z++;
		i++;
		j = 0;
	}
	free(buff);
	cmds[z] = NULL;
	return (cmds);
}
/**
 * getinput - geting input from given file
 * @str: input file path
 * Return: pointer to an array of strings
 */
char **getinput(char *str)
{
	char *buff = NULL, **cmds = NULL;
	int fp, i;

	fp = open(str, O_RDONLY);
	if (fp == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", str);
		exit(EXIT_FAILURE);
	}
	buff = malloc(10001 * sizeof(char));
	if (buff == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	i = read(fp, buff, 10000);
	buff[i] = '\0';
	close(fp);
	cmds = tokenise(buff, '\n');
	return (cmds);
}
