# include "monty.h"
/**
 * _pchar - print char at the top of stack
 * @h: input headnode
 * @data: input
 */
void _pchar(stack_t **h, int data)
{
	(void)data;
	printf("%c\n", (*h)->n);
}
