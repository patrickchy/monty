#include "monty.h"

/**
 * sub - subtracts the top element of a stack from the second top
 * @stack: stack which operation is to be done.
 * @line_number: line number which elements is to be subtracted.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*(*stack)).next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*(*stack)).n;

	/*Call the pop function on the stack*/
	pop(stack, line_number);
}

/**
* div_func - Divides the second top element of the stack from the top element
* @stack: pointer to the stack
* @line_number: the line number in the file
*/
void div_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*(*stack)).next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*(*stack)).n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*(*stack)).next->n /= (*(*stack)).n;

	/*call the pop function on the stack*/
	pop(stack, line_number);
}


/**
* mul_func - subtracts the top element of a stack from the second top
* @stack: stack for which operation is to be done.
* @line_number: line numbe for which elements are to be multiplied.
*/
void mul_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);

		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;

	pop(stack, line_number);
}


/**
* mod - this function calculate the mod of 2 elements in a stack.
* @stack: stack which operation is to be done.
* @line_number: line number for which modulus operation is to be done.
* Return: void.
*/

void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*(*stack)).next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*Validated zero division error*/
	if ((*(*stack)).n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*(*stack)).next->n %= (*(*stack)).n;

	pop(stack, line_number);
}


/**
* pchar - this fuction prints a character from a stack.
* @stack: stack for which character is to be printed from.
* @line_number: line number of which element is to be printed.
*/

void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*(*stack)).n >= 0 && (*(*stack)).n <= 127)
	{

		putchar((*(*stack)).n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
