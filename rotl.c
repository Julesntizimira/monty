# include "monty.h"
/**
 * _rotl - rotate the list
 * @h: input node
 * @data: data;
 */
void _rotl(stack_t **h, int data)
{
	stack_t *tmp = *h, *pt = NULL;

	(void)data;

	if (head != NULL && head->next != NULL)
	{
		*h = (*h)->next;
		(*h)->prev = NULL;

		pt = *h;
		while (pt->next != NULL)
		{
			pt = pt->next;
		}
		pt->next = tmp;
		tmp->prev = pt;
		tmp->next = NULL;
	}
}
