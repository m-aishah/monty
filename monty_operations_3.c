#include "monty.h"

/**
 * mul_top_two - multiplies the top two elements of a stack.
 * @stack: Double pointer to the head of the list.
 * @line_number: The line the mul opcode was called from.
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
 * mod_top_two - computes the remainder from the division of the
 * second top element of the stack by the top element of the stack.
 * @stack: Double pointer to the head of the list.
 * @line_number: The line the mod opcode was called from.
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

/**
 * print_top_char - prints the value (char) at the top of the stack.
 * @stack: Double pointer to the head of the list.
 * @line_number: The line the opcode was called from.
 */
void print_top_char(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	temp = temp->next;

	if (temp == NULL)
	{
		set_op_tok_error(pchar_error_one(line_number));
		return;
	}
	if (temp->n < 0 || temp->n > 127)
	{
		set_op_tok_error(pchar_error_two(line_number));
		return;
	}

	printf("%c\n", temp->n);
}

/**
 * print_top_str - prints the strings
 *		starting at the top of the stack.
 * @stack: Double pointer to the head of the list
 * @line_number: The line the opcode was called from.
 */
void print_top_str(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	temp = (*stack)->next;

	while (temp != NULL && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotate_to_top - rotates the stack to the top
 * @stack: Double pointer to the head of the list.
 * @line_number: The line the opcode was called from.
 */
void rotate_to_top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2;

	(void)line_number;

	temp = (*stack)->next;
	temp2 = (*stack)->next;

	if (temp == NULL || temp->next == NULL)
		return;
	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	(*stack)->next = temp->next;
	temp->next->prev = (*stack);
	temp->prev = temp2;
	temp->next = NULL;
	temp2->next = temp;
}
