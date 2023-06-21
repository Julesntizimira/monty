# include "monty.h"
int _strlen(char *s)
{
	 int len = 0;
	 if (s == NULL)
		 return (0);
	 while(*s != '\0')
	 {
		 s++;
		 len++;
	 }
	 return (len);
}
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
char **getinput(char *str)
{
	char *buff = NULL, **cmds = NULL;
	int fp, i;
	
	fp = open(str, O_RDONLY);
	buff = malloc(10001 * sizeof(char));
	if (buff == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	i = read(fp, buff, 10000);
	buff[i] = '\0';
	cmds = tokenise(buff, '\n');
	return (cmds);
}
