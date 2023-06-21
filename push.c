# include "monty.h"
/**
 * _push - adds a new node at the top of stack
 * @head: input head node
 * @data: newnode data
 */
void _push(stack_t **h, int data)
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
		tmp->prev = newnode;
		newnode->next = tmp;
		*h = newnode;
	}
}
