# include "monty.h"
/**
 * _rotr - rotate the list to the botom
 * @h: input node
 * @data: data;
 */
void _rotr(stack_t **h, int data)
{
	stack_t *tmp = *h;

	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp != *h)
		_rotl(&*h, data);
}
