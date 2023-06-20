# include "monty.h"

void _pint(stack_t **h, int data)
{
	(void)data;
	printf("%d\n", (*h)->n);
}
