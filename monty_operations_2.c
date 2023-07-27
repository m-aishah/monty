#include "monty.h"

/**
 * swap_top_two - a function to swap the top two elements of a stack
 * @stack: double pointer to the head of the list
 * @line_number: line number
 *
*/

void swap_top_two(stack_t **stack, unsigned int line_number)
{
    stack_t *temp, *temp2;
    temp = (*stack)->next;
    temp2 = (*stack)->next->next;

    if (temp == NULL || temp2 == NULL)
    {
        set_op_tok_error(swap_error(line_number));
        return;
    }

    temp->next = temp2->next;
    temp->prev = temp2;
    temp2->next = temp;
    temp2->prev = (*stack);
    (*stack)->next = temp2;
    if (temp->next != NULL)
    {
        temp->next->prev = temp;
    }


}
