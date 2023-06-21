# include "monty.h"
/**
 * _pstr - function that prints all the elements of a stack_t list.
 * @h: input node
 * @data: data;
 */
void _pstr(stack_t **h, int data)
{
	stack_t *tmp = *h;

	(void)data;

	if (head != NULL)
	{
		while (tmp != NULL && tmp->n > 0 && tmp->n < 128)
		{
			printf("%c", tmp->n);
			tmp = tmp->next;
		}
	}
	printf("\n");
}
