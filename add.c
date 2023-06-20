# include "monty.h"

void _add(stack_t **h, int data)
{
	int tmp = 0;

	(void)data;
	tmp = (*h)->n + (*h)->next->n;
	_pop(&head, 0);
	_pop(&head, 0);
	_push(&head, tmp);

}
void _sub(stack_t **h, int data)
{
        int tmp = 0;

        (void)data;
        tmp = (*h)->next->n - (*h)->n;
        _pop(&head, 0);
        _pop(&head, 0);
        _push(&head, tmp);

}
void _div(stack_t **h, int data)
{
        int tmp = 0;

        (void)data;
        tmp = (*h)->next->n / (*h)->n;
        _pop(&head, 0);
        _pop(&head, 0);
        _push(&head, tmp);

}
void _mul(stack_t **h, int data)
{
        int tmp = 0;

        (void)data;
        tmp = (*h)->next->n * (*h)->n;
        _pop(&head, 0);
        _pop(&head, 0);
        _push(&head, tmp);

}
void _mod(stack_t **h, int data)
{
        int tmp = 0;

        (void)data;
        tmp = (*h)->next->n % (*h)->n;
        _pop(&head, 0);
        _pop(&head, 0);
        _push(&head, tmp);

}
