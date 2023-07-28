#include "monty.h"

/**
 * rotate_to_bottom - a function that rotates the stack to the bottom
 * @stack: double pointer to the head of the list
 * @line_number: line number
 */
void rotate_to_bottom(stack_t **stack, unsigned int line_number)
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
	temp2->prev->next = NULL;
	temp2->prev = (*stack);
	temp2->next = temp;
	(*stack)->next = temp2;
	temp->prev = temp2;
}

/**
 * stack_mode - a function to put the doubly linked list in stack mode
 * @stack: double pointer to the head of the list
 * @line_number: line number
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(*stack)->n = 0;
}

/**
 * queue_mode - a function to put the doubly linked list in queue mode
 * @stack: double pointer to the head of the list
 * @line_number: line number
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(*stack)->n = 1;
}
