# include "monty.h"
/**
 * _rotr - rotate the list to the botom
 * @h: input node
 * @data: data;
 */
void _rotr(stack_t **h, int data)
{
	stack_t *tmp = *h, *pr = NULL;

	(void)data;

	if (head != NULL)
	{
		while ((*h)->next != NULL)
		{
			*h = (*h)->next;
			tmp->next = pr;
			tmp->prev = *h;
			pr = tmp;
			tmp = *h;
		}
		(*h)->next = pr;
		(*h)->prev = NULL;
	}
}
