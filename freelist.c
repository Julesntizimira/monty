# include "monty.h"

void freelist(stack_t **h)
{
	if (*h != NULL)
	{
		while ((*h)->next != NULL)
		{
			*h = (*h)->next;
			free((*h)->prev);
		}
		free(*h);
		*h = NULL;
	}	
}
