# include "monty.h"
/**
 * _pop - pint
 * @h: input node
 * @n: data;
 */
void _pop(stack_t **h, int n)
{
	stack_t *tmp = *h;

	(void)n;
	if (tmp->next != NULL)
	{
		*h = tmp->next;
		(*h)->prev = NULL;
		free(tmp);
	}
	else
	{
		free(tmp);
		*h = NULL;
	}
}
