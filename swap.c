# include "monty.h"
/**
 * _swap - swap 2top elements
 * @h: input node
 * @n: data;
 */
void _swap(stack_t **h, int n)
{
	int tmp = (*h)->n;

	(void)n;
	(*h)->n = (*h)->next->n;
	(*h)->next->n = tmp;
}
