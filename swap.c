# include "monty.h"

void _swap(stack_t **h, int n)
{

	int tmp = (*h)->n;
	
	(void)n;

	(*h)->n = (*h)->next->n;
	(*h)->next->n = tmp;
}
