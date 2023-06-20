# include "monty.h"

void _swap(stack_t **h, int n)
{
	(void)n;

	int tmp = (*h)->n;
	(*h)->n = (*h)->next->n;
	(*h)->next->n = tmp;
}
