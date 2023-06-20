# include "monty.h"
/**
 * _pall - function that prints all the elements of a stack_t list.
 * @head: input node
 * @n: data;
 */
void _pall(stack_t **head, int n)
{
	stack_t *tmp = NULL;
	
	(void)n;
	if (*head == NULL || head == NULL)
		return;
        tmp = *head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
