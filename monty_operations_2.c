#include "monty.h"

/**
 * swap_top_two - a function to swap the top two elements of a stack
 * @stack: double pointer to the head of the list
 * @line_number: line number
 *
 */

void swap_top_two(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp, *temp, *temp2;
    tmp = NULL;
    temp = (*stack)->next;
    temp2 = (*stack)->next->next;

    if (temp == NULL || temp2 == NULL)
    {
        set_op_tok_error(swap_error(line_number));
        return;
    }

    tmp->n = temp->n;
    temp->n = temp2->n;
    temp2->n = tmp->n;

    /**
     * temp->next = temp2->next;
        temp->prev = temp 2;
        temp2->next = temp;
        temp2->prev = (*stack);
        (*stack)->next = temp2;


        if (temp->next != NULL)
        {
            temp->next->prev = temp;
        }
    */
}

/**
 * add_top_two - a function to add the top two elements of a stack
 * @stack: double pointer to the head of the list
 * @line_number: line number
 *
 */

void add_top_two(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = (*stack)->next;
    stack_t *sum = NULL;

    if (temp == NULL || temp->next == NULL)
    {
        set_op_tok_error(add_error(line_number));
        return;
    }
    sum->n = temp->n + temp->next->n;
    temp->next->n = sum->n;
    pop_from_stack(stack, line_number);
}

/**
 * do nothing - a function to do nothing
 * @stack: unused variable
 * @line_number: unused variable
 */

void do_nothing(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;

    return;
}
