#include "monty.h"

/**
 * mul_top_two - a function to mul the top two elements of a stack
 * @stack: double pointer to the head of the list
 * @line_number: line number
 *
 */

void mul_top_two(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = (*stack)->next;

    if (temp == NULL || temp->next == NULL)
    {
        set_op_tok_error(short_stack_errors(line_number, "mul"));
        return;
    }
    temp->next->n *= temp->n;
    pop_from_stack(stack, line_number);
}

/**
 * mod_top_two - a function to compute the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @stack: double pointer to the head of the list
 * @line_number: line number
 *
 */

void mod_top_two(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = (*stack)->next;

    if (temp == NULL || temp->next == NULL)
    {
        set_op_tok_error(short_stack_errors(line_number, "mod"));
        return;
    }
    if (temp->n == 0)
    {
        set_op_tok_error(div_error(line_number));
        return;
    }

    temp->next->n %= temp->n;
    pop_from_stack(stack, line_number);
}