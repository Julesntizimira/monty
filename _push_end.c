# include "monty.h"
/**
 * _push_ - adds a new node at the end of stack
 * @h: input head node
 * @data: newnode data
 */
void _push_(stack_t **h, int data)
{
	stack_t *tmp = NULL, *newnode = NULL;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newnode->prev = NULL;
	newnode->n = data;
	newnode->next = NULL;
	if (*h == NULL)
	{
		*h = newnode;
		return;
	}
	else
	{
		tmp = *h;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = newnode;
		newnode->prev = tmp;
	}
}
