# include "monty.h"
/**
 * _add - stack operation
 * @h: input head node
 * @data: input data
 */
void _add(stack_t **h, int data)
{
	int tmp = 0;

	(void)data;
	tmp = (*h)->n + (*h)->next->n;
	_pop(&head, 0);
	_pop(&head, 0);
	_push(&head, tmp);
}
/**
 * _sub - stack operation
 * @h: input head node
 * @data: input data
 */
void _sub(stack_t **h, int data)
{
	int tmp = 0;

	(void)data;
	tmp = (*h)->next->n - (*h)->n;
	_pop(&head, 0);
	_pop(&head, 0);
	_push(&head, tmp);
}
/**
 * _div - stack operation
 * @h: input head node
 * @data: input data
 */
void _div(stack_t **h, int data)
{
	int tmp = 0;

	(void)data;
	tmp = (*h)->next->n / (*h)->n;
	_pop(&head, 0);
	_pop(&head, 0);
	_push(&head, tmp);
}
/**
 * _mul - stack operation
 * @h: input head node
 * @data: input data
 */
void _mul(stack_t **h, int data)
{
	int tmp = 0;

	(void)data;
	tmp = (*h)->next->n * (*h)->n;
	_pop(&head, 0);
	_pop(&head, 0);
	_push(&head, tmp);

}
/**
 * _mod - stack operation
 * @h: input head node
 * @data: input data
 */
void _mod(stack_t **h, int data)
{
	int tmp = 0;

	(void)data;
	tmp = (*h)->next->n % (*h)->n;
	_pop(&head, 0);
	_pop(&head, 0);
	_push(&head, tmp);
}
