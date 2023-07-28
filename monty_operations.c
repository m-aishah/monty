#include "monty.h"

void push_to_stack(stack_t **stack, unsigned int line_number);
void print_all_stack(stack_t **stack, unsigned int line_number);
int is_valid_int(void);
void print_top_stack(stack_t **stack, unsigned int line_number);

/**
 * push_to_stack - Function to push an integer to a stack.
 * @stack: A pointer to the top (mode node) of a stack.
 * @line_number: The number of the line containing the push
 * code in the bytecode file.
 */
void push_to_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		malloc_error();
		set_op_tok_error(EXIT_FAILURE);
		return;
	}

	if (all_op_tokens[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}

	if (is_valid_int() == 0)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}
	newNode->n = atoi(all_op_tokens[1]);
	if (check_mode(*stack) == 0) /* STACK mode insert at the front */
	{
		tmp = (*stack)->next;
		newNode->prev = *stack;
		newNode->next = tmp;
		if (tmp)
		tmp->prev = newNode;
		(*stack)->next = newNode;
	}
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
		tmp = tmp->next;
		tmp->next = newNode;
		newNode->prev = tmp;
		newNode->next = NULL;
	}
	/* else  QUEUE mode insert at the end */
}

/**
 * is_valid_int - Function to check if a string can
 * be made into a valid integer.
 * Return: 1, if it can be a valid integer, else 0.
 */

int is_valid_int(void)
{
	int i;

	for (i = 0; all_op_tokens[1][i]; i++)
	{
		if (i == 0 && all_op_tokens[1][i] == '-')
			continue;
		if (all_op_tokens[1][i] < '0' || all_op_tokens[1][i] > '9')
		{
			return (0);
		}
	}
	return (1);
}

/**
 * print_all_stack - a function to print the stack (value)
 * @stack: double pointer to the head of the list
 * @line_number: line number
 */
void print_all_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	temp = temp->next;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * print_top_stack - a function to print the value at the top of the stack
 * @stack: double pointer to the head of the list
 * @line_number: line number
 */
void print_top_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	temp = temp->next;
	if (temp == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}
	printf("%d\n", temp->n);
}

/**
 * pop_from_stack - a function to pop the value at the top of the stack
 * @stack: double pointer to the head of the list
 * @line_number: line number
 */

void pop_from_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL, *temp2 = NULL;

	temp = (*stack)->next;
	if (temp == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}
	temp2 = temp->next;
	free(temp);
	(*stack)->next = temp2;
	if (temp2)
		temp2->prev = (*stack);
}
