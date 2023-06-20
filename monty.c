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

        char **cmds = NULL, token[1024];
        int i = 0, j = 0, z = 0, count = 0;

        cmds = malloc(3 * sizeof(char *));
        if (cmds == NULL)
        {
                free(buff);
                printf("Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
        i = 0;
        while (buff[i] != '\0')
        {
		if (buff[i] != ' ' && buff[i] != '\t')
		{
			while (buff[i] != ' ' && buff[i] != '\t' && buff[i] != '\0')
			{
				token[j] = buff[i];
				j++;
				i++;
			}
			token[j] = '\0';
			cmds[z] = _strdup(token);
			z++;
			j = 0;
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
		{ NULL, NULL}
	};
	cmds = parse(cmd);	
	if (cmds[1])
		data = atoi(cmds[1]);
	if (strcmp(cmds[0], "push") == 0)
	{
		if (cmds[1][0] != '0' && data == 0)
		{
			printf("L%d: usage: push integer\n", line_number);
			_free(new);
			_free(cmds);
			freelist(&head);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp(cmds[0], "pint") == 0 && head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		_free(new);
		_free(cmds);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(cmds[0], "pop") == 0 && head == NULL)
        {
                printf("L%d: can't pop, stack empty\n", line_number);
                _free(new);
                _free(cmds);
                exit(EXIT_FAILURE);
        }
	else if (strcmp(cmds[0], "swap") == 0 && (head == NULL || head->next == NULL))
        {
                printf("L%d: can't swap, stack too short\n", line_number);
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
	char *path = NULL, *buff = NULL;
	char **new = NULL;
	int line_number = 1, i = 0;
	head = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	path = argv[1];

	if (access(path, R_OK) != 0)
	{
		printf("Error: Can't open file %s\n", path);
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

}
