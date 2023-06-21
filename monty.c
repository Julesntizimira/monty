# include "monty.h"

stack_t *head;

void _free(char **cmds)
{
	int i = 0;

	if (cmds == NULL)
		return;
	while(cmds[i] != NULL)
	{
		free(cmds[i]);
		i++;
	}
	free(cmds);
}
char **parse(char *buff)
{

        char **cmds = NULL, token[1024] = {'\0'};
        int i = 0, j = 0, z = 0, count = 0;

        while (buff[i] != '\0')
        {
		  if (buff[i] != ' ' && buff[i] != '\t')
		  {
			  count++;
			  while (buff[i] != ' ' && buff[i] != '\t' && buff[i] != '\0')
			  {
				  i++;
			  }
			  continue;
		  }
		  i++;
	}
        count++;
	cmds = malloc(count * sizeof(char *));
        if (cmds == NULL)
        {
		fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
	i = 0;
	while (buff[i] != '\0')
        {
		if (buff[i] != ' ' && buff[i] != '\t')
		{
			j = 0;
			while (buff[i] != ' ' && buff[i] != '\t' && buff[i] != '\0')
			{
				token[j] = buff[i];
				j++;
				i++;
			}
			token[j] = '\0';
			cmds[z] = _strdup(token);
			z++;
			continue;
		}
		i++;

        }
	cmds[z] = NULL;
        return (cmds);
}

void execute(char **new, char *cmd, int line_number)
{
	char **cmds = NULL;
	int data = 0, i = 0;

	instruction_t instr[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mod", _mod},
		{"mul", _mul},
		{ NULL, NULL}
	};
	cmds = parse(cmd);

	if (cmds[1])
	{
		data = atoi(cmds[1]);
	}

	if (strcmp(cmds[0], "nop") == 0)
		return;

	if (cmds[0][0] == '#')
		return;
	if (strcmp(cmds[0], "push") == 0)
	{
		if (cmds[1][0] != '0' && data == 0)
		{
			fprintf(stderr,"L%d: usage: push integer\n", line_number);
			_free(new);
			_free(cmds);
			freelist(&head);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp(cmds[0], "pint") == 0 && head == NULL)
	{
		fprintf(stderr,"L%d: can't pint, stack empty\n", line_number);
		_free(new);
		_free(cmds);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(cmds[0], "pop") == 0 && head == NULL)
        {
                fprintf(stderr,"L%d: can't pop, stack empty\n", line_number);
                _free(new);
                _free(cmds);
                exit(EXIT_FAILURE);
        }
	else if (strcmp(cmds[0], "swap") == 0 && (head == NULL || head->next == NULL))
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
                _free(new);
                _free(cmds);
                exit(EXIT_FAILURE);
        }
	else if (strcmp(cmds[0], "add") == 0 && (head == NULL || head->next == NULL))
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
                _free(new);
                _free(cmds);
                exit(EXIT_FAILURE);
        }
	else if (strcmp(cmds[0], "sub") == 0 && (head == NULL || head->next == NULL))
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
                _free(new);
                _free(cmds);
                exit(EXIT_FAILURE);
        }
	else if (strcmp(cmds[0], "div") == 0 && (head == NULL || head->next == NULL))
        {
                fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
                _free(new);
                _free(cmds);
                exit(EXIT_FAILURE);
        }
	else if (head->n == 0)
        {
		fprintf(stderr, "L%d: division by zero\n", line_number);
                _free(new);
                _free(cmds);
                exit(EXIT_FAILURE);
        }
	while (instr[i].opcode != NULL)
	{
		if (strcmp(instr[i].opcode, cmds[0]) == 0)
		{
			instr[i].f(&head, data);
		}
		i++;
	}
	/*_free(cmds);*/
}
int main(int argc, char *argv[])
{
	char *path = NULL;
	char **new = NULL;
	int line_number = 1, i = 0;
	head = NULL;

	if (argc != 2)
	{
		fprintf(stderr,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	path = argv[1];

	if (access(path, R_OK) != 0)
	{
		fprintf(stderr,"Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}
	new = getinput(path);
	
	while (new[i] != NULL)
	{
		execute(new, new[i], line_number);
		line_number++;
		i++;
	}
	_free(new);
	freelist(&head);

	return (0);
}
