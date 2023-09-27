#include "monty.h"

/**
 * swap_top_two - swaps the top two elements of a stack.
 * @stack: Double pointer to the head of the list.
 * @line_number: The line the swap opcode was called from.
 *
 */
void swap_top_two(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL, *temp2 = NULL;

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

/**
 * add_top_two - a function to add the top two elements of a stack.
 * @stack: Double pointer to the head of the list.
 * @line_number: The line the add opcode was called from.
 */
void add_top_two(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	if (temp == NULL || temp->next == NULL)
	{
		set_op_tok_error(add_error(line_number));
		return;
	}
	temp->next->n += temp->n;
	pop_from_stack(stack, line_number);
}

/**
 * do_nothing - Does nothing.
 * @stack: Unused variable.
 * @line_number: Unused variable.
 */
void do_nothing(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_top_two - subtracts the top element of a stack from the second top.
 * @stack: Double pointer to the head of the list
 * @line_number: The line the sub opcode was called from.
 *
 */
void sub_top_two(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	if (temp == NULL || temp->next == NULL)
	{
		set_op_tok_error(short_stack_errors(line_number, "sub"));
		return;
	}
	temp->next->n -= temp->n;
	pop_from_stack(stack, line_number);
}

/**
 * div_top_two - divides the second top element of the stack by the top element of the stack.
 * @stack: Double pointer to the head of the list.
 * @line_number: The line the div opcode was called from.
 */

void div_top_two(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	if (temp == NULL || temp->next == NULL)
	{
		set_op_tok_error(short_stack_errors(line_number, "div"));
		return;
	}
	if (temp->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	temp->next->n /= temp->n;
	pop_from_stack(stack, line_number);
}
