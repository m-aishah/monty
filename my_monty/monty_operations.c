#include "monty.h"

void push_to_stack(stack_t **stack, unsigned int line_number);
void print_all_stack(stack_t **stack, unsigned int line_number);
int is_valid_int();
/**
 * push_to_stack - Function to push an integer to a stack.
 * @stack: A pointer to the top (mode node) of a stack.
 * @line_number: The number of the line containing the push code in the bytecode file.
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
	printf("Pushed %d\n", newNode->n);
	if (check_mode(*stack) == 0) /* STACK mode insert at the front */
	{
		tmp = (*stack)->next;
		newNode->prev = *stack;
		newNode->next = tmp;
		if (tmp)
			tmp->prev = newNode;
		(*stack)->next = newNode;
	}
	/* else  QUEUE mode insert at the end */
}

/**
 * is_valid_int: Function to check if a string can be made into a valid integer.
 * @value: The string in question.
 * Return: 1, if it can be a valid integer
 *              else, 0.
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

void print_all_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;

	printf("pall :)");
}
