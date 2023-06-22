# include "monty.h"
/**
 * execute1 - parse input
 * @new: input
 * @cmd: input
 * @line_number: input
 * Return: 0 or 1
 */
int execute1(char **new, char *cmd, int line_number)
{
	char **cmds = NULL;
	int data = 0, j = 0, i = 0;
	instruction_t instr[] = {{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add}, {"sub", _sub},
		{"div", _div}, {"mod", _mod}, {"mul", _mul}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotr", _rotr}, {"rotl", _rotl}, { NULL, NULL}};

	cmds = parse(cmd);
	if (cmds == NULL)
		return (j);
	if (_strcmp(cmds[0], "nop") == 0)
	{
		_free(cmds);
		return (j);
	}
	if (cmds[0][0] == '#')
	{
		_free(cmds);
		return (j);
	}
	if (cmds[1])
		data = atoi(cmds[1]);
	error_check(new, cmds, line_number, data);
	while (instr[i].opcode != NULL)
	{
		if (_strcmp(instr[i].opcode, cmds[0]) == 0)
		{
			instr[i].f(&head, data);
			break;
		}
		i++;
	}
	if (_strcmp(cmds[0], "stack") == 0)
		j = 0;
	else if (_strcmp(cmds[0], "queue") == 0)
		j = 1;
	else if (instr[i].opcode == NULL)
		handle_errors(new, cmds, line_number, 10);
	_free(cmds);
	return (j);
}

/**
 * execute2 - parse input
 * @new: input
 * @cmd: input
 * @line_number: input
 * Return: int
 */

int execute2(char **new, char *cmd, int line_number)
{
	char **cmds = NULL;
	int data = 0, j = 1, i = 0;
	instruction_t instr[] = {{"push", _push_}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add}, {"sub", _sub},
		{"div", _div}, {"mod", _mod}, {"mul", _mul}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotr", _rotr}, {"rotl", _rotl}, { NULL, NULL}};

	cmds = parse(cmd);
	if (cmds == NULL)
		return (j);
	if (_strcmp(cmds[0], "nop") == 0)
	{
		_free(cmds);
		return (j);
	}
	if (cmds[0][0] == '#')
	{
		_free(cmds);
		return (j);
	}
	if (cmds[1])
		data = atoi(cmds[1]);
	error_check(new, cmds, line_number, data);
	while (instr[i].opcode != NULL)
	{
		if (_strcmp(instr[i].opcode, cmds[0]) == 0)
		{
			instr[i].f(&head, data);
			break;
		}
		i++;
	}
	if (_strcmp(cmds[0], "stack") == 0)
		j = 0;
	else if (_strcmp(cmds[0], "queue") == 0)
		j = 1;
	else if (instr[i].opcode == NULL)
		handle_errors(new, cmds, line_number, 10);
	_free(cmds);
	return (j);
}
