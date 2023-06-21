# include "monty.h"
/**
 * _pall - function that prints all the elements of a stack_t list.
 * @h: input node
 * @data: data;
 */
void _pall(stack_t **h, int data)
{

	stack_t *tmp = *h;

	(void)data;

	if (head != NULL)
	{
		while (tmp != NULL)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}
}
