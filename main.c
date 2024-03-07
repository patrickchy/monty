#define _POSIX_C_SOURCE 200809L
#include "monty.h"
/**
* main - this is the main function entry point.
* @argc: command line argument count.
* @argv: command line argument vector array.
* Return: 0 on success.
*/

int main(int argc, char *argv[]);
int main(int argc, char *argv[])
{
	FILE *fd; /*file descriptor variable.*/

	char *file_name;

	char *buffer_ptr;

	size_t buff_size;

	stack_t *stack = NULL;

	unsigned int line_number = 0;

	instruction_t instructions[] = {

		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_func},
		{"mul", mul_func},
		{"div", div_func},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}
	};

	file_name = argv[1];

	fd = fopen(file_name, "r");

	/*Validate number of command line argument.*/

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");

		exit(EXIT_FAILURE);
	}

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);

		exit(EXIT_FAILURE);
	}

	/*I used the getline function to read from the file stream (file)*/
	while (getline(&buffer_ptr, &buff_size, fd) != -1)
	{
		char *opcode_token;

		line_number += 1; /*Proceeds to read the next line in file.*/

		/*Checks for comment on a line*/
		if (buffer_ptr[0] == '#' || buffer_ptr[0] == '\n')
		{
			continue;
		}

		opcode_token = strtok(buffer_ptr, " \n\t");

		if (opcode_token != NULL) /*Checks if it's not end of line*/
		{
			int i = 0;

			while (instructions[i].opcode != NULL)
			{
				if (strcmp(opcode_token, instructions[i].opcode) == 0)
				{
					instructions[i].f(&stack, line_number);
					break;
				}
				i += 1;
			}

			/*Check for invalid opcodes*/
			if (instructions[i].opcode == NULL)
			{
				char *op = opcode_token;

				unsigned int ln = line_number;

				char *msg = "L%u: unknown instruction %s\n";

				fprintf(stderr, msg, ln, op);
				fclose(fd);
				free(buffer_ptr);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
		}
	}

	fclose(fd);
	free(buffer_ptr);
	free_stack(&stack);
	return (0);
}
