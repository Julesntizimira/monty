# include "monty.h"
/**
 * _pint - pint
 * @h: input node
 * @data: data;
 */
void _pint(stack_t **h, int data)
{
	(void)data;
	printf("%d\n", (*h)->n);
}
