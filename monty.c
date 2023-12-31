# include "monty.h"

stack_t *head;
/**
 * parse - parse input
 * @buff: input
 * Return: 2d Array
 */
char **parse(char *buff)
{
	char **cmds = NULL, token[1024] = {'\0'};
	int i = 0, j = 0, z = 0, count = countbuff(buff);

	cmds = malloc((count + 1) * sizeof(char *));
	if (cmds == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
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
			if ((z == 1) && (_strcmp(token, "-0") == 0))
				cmds[z] = _strdup("0");
			else
				cmds[z] = _strdup(token);
			z++;
			continue;
		}
		i++;
	}
	if (z == 0)
	{
		free(cmds);
		return (NULL);
	}
	cmds[z] = NULL;
	return (cmds);
}
/**
 * handle_errors - parse input
 * @new: input
 * @cmds: input
 * @line_number: input
 * @error_number: input
 */
void handle_errors(char **new, char **cmds, int line_number, int error_number)
{
	char *str[] = {
		"usage: push integer",
		"can't pint, stack empty",
		"can't pop an empty stack",
		"can't swap, stack too short",
		"can't add, stack too short",
		"can't sub, stack too short",
		"can't div, stack too short",
		"division by zero",
		"can't mod, stack too short",
		"can't mul, stack too short",
		"unknown instruction",
		"can't pchar, stack empty",
		"can't pchar, value out of range"
	};
	if (error_number == 10)
	{
		fprintf(stderr, "L%d: %s %s\n", line_number,
				str[error_number], cmds[0]);
	}
	else
	{
		fprintf(stderr, "L%d: %s\n", line_number,
				str[error_number]);
	}

	_free(new);
	_free(cmds);
	freelist(&head);
	exit(EXIT_FAILURE);
}
/**
 * checkdata - check data if there is no error
 * @cmds: input
 * @data: input
 * Return: 0 or 1
 */
int checkdata(char **cmds, int data)
{
	int i = _strlen(cmds[1]);
	int count = 0;

	if (data < 0)
	{
		data *= -1;
		count++;
	}
	do {
		data /= 10;
		count++;
	} while (data > 0);

	if (count != i)
	{
		return (1);
	}
	return (0);
}
/**
 * error_check - parse input
 * @new: input
 * @cmds: input
 * @line_number: input
 * @data: data input
 */
void error_check(char **new, char **cmds, int line_number, int data)
{
	if (_strcmp(cmds[0], "push") == 0)
	{
		if (((!cmds[1]) || (cmds[1][0] != '0' && data == 0)) ||
				(checkdata(cmds, data) != 0))
			handle_errors(new, cmds, line_number, 0);
	}
	else if (_strcmp(cmds[0], "pint") == 0 && head == NULL)
		handle_errors(new, cmds, line_number, 1);
	else if (_strcmp(cmds[0], "pop") == 0 && head == NULL)
		handle_errors(new, cmds, line_number, 2);
	else if (_strcmp(cmds[0], "swap") == 0
			&& (head == NULL || head->next == NULL))
		handle_errors(new, cmds, line_number, 3);
	else if (_strcmp(cmds[0], "add") == 0 && (head == NULL || head->next == NULL))
		handle_errors(new, cmds, line_number, 4);
	else if (_strcmp(cmds[0], "sub") == 0 && (head == NULL || head->next == NULL))
		handle_errors(new, cmds, line_number, 5);
	else if (_strcmp(cmds[0], "div") == 0 && (head == NULL || head->next == NULL))
		handle_errors(new, cmds, line_number, 6);
	else if (_strcmp(cmds[0], "div") == 0 && head->n == 0)
		handle_errors(new, cmds, line_number, 7);
	else if (_strcmp(cmds[0], "mod") == 0 && (head == NULL || head->next == NULL))
		handle_errors(new, cmds, line_number, 8);
	else if (_strcmp(cmds[0], "mod") == 0 && head->n == 0)
		handle_errors(new, cmds, line_number, 7);
	else if (_strcmp(cmds[0], "mul") == 0 && (head == NULL || head->next == NULL))
		handle_errors(new, cmds, line_number, 9);
	else if (_strcmp(cmds[0], "pchar") == 0 && (head == NULL))
		handle_errors(new, cmds, line_number, 11);
	else if (_strcmp(cmds[0], "pchar") == 0 && (head->n < 0 || head->n > 127))
		handle_errors(new, cmds, line_number, 12);
}
/**
 * main - main function
 * @argc: number of argument
 * @argv: arguments array
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	char *path = NULL;
	char **new = NULL;
	int line_number = 1, j = 0, i = 0;
	int *line_number_ptr = &line_number;

	head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		fflush(NULL);
		exit(EXIT_FAILURE);
	}
	path = argv[1];
	new = getinput(path, line_number_ptr);
	while (new[i] != NULL)
	{
		while (j == 0 && new[i] != NULL)
		{
			j = execute1(new, new[i], line_number);
			line_number++;
			i++;
		}
		while (j == 1 && new[i] != NULL)
		{
			j = execute2(new, new[i], line_number);
			line_number++;
			i++;
		}
	}
	_free(new);
	freelist(&head);

	return (0);
}
