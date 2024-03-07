#include "monty.h"

/**
* is_a_number - this funtion checks for a valid integer.
* @ch_arr: number to be checked.
* Return: True if number is valid esle False.
*/

bool is_a_number(char *ch_arr)
{
	if (*ch_arr == '+' || *ch_arr == '-')
	{
		ch_arr++;
	}

	while (*ch_arr != '\0')
	{
		if (!isdigit(*ch_arr))
		{
			return (false);
		}

		ch_arr++;
	}

	return (true);
}

/**
* free_stack - this function frees a stack.
* @stack: stck to be free'd.
* Return: void.
*/

void free_stack(stack_t **stack)
{
	stack_t *head;

	while (*stack != NULL)
	{
		head = *stack;

		*stack = (*(*stack)).next;

		free(head);
	}
}
