# ifndef MONTY_H
# define MONTY_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, int line_number);
} instruction_t;
extern stack_t *head;
char **parse(char *buff);
void handle_errors(char **new, char **cmds, int line_number, int error_number);
void error_check(char **new, char **cmds, int line_number, int data);
int execute1(char **new, char *cmd, int line_number);
int execute2(char **new, char *cmd, int line_number);
void _push_(stack_t **h, int data);
void _push(stack_t **head, int data);
void _pall(stack_t **h, int data);
char **getinput(char *str, int *line_number);
char **tokenise(char *buff, char delim, int *line_number);
char *_strdup(char *str);
int _strlen(char *s);
int _strcmp(char *str1, char *str2);
void freelist(stack_t **h);
void _pop(stack_t **h, int n);
void _swap(stack_t **h, int n);
void _pint(stack_t **h, int data);
void _add(stack_t **h, int data);
void _sub(stack_t **h, int data);
void _div(stack_t **h, int data);
void _mul(stack_t **h, int data);
void _mod(stack_t **h, int data);
int countbuff(char *buff);
void _free(char **cmds);
void _pstr(stack_t **h, int data);
void _pchar(stack_t **h, int data);
void _rotl(stack_t **h, int data);
void _rotr(stack_t **h, int data);
#endif
