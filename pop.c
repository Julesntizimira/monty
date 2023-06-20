# include "monty.h"

void _pop(stack_t **h, int n)
{
	stack_t *tmp = *h;


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
