#include "monty.h"
void nothing(void);
int data;
/**
 * main - Entry point
 * @argc: the argument count
 * @argv: the argument vector
 * Return: 0
 *
 */
int main(int argc, char **argv)
{
	char *arg, *token, *line, *endptr, *trimmed_token, *instruction;
	FILE *file;
	size_t len;
	int i, value;
	char line_buf[1024];
	stack_t *stack = NULL;
	unsigned int line_num = 0;
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	/* Check if arguments supplied to monty program is 2*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

    /* Open monty bytes file */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line_buf, sizeof(line_buf), file))
	{
		/* Pointer to the current line */
		line = line_buf;
		line_num++;

		/* Tokenize the line using semicolon delimiter */
		while ((token = __strtok_r(line, ";$", &line)) != NULL)
		{
			/* Remove spaces before and after token */
			trimmed_token = token;
			while (*trimmed_token == ' ' || *trimmed_token == '\t')
				trimmed_token++;
			len = strlen(trimmed_token);
			while (len > 0 && (trimmed_token[len - 1] == ' ' ||
				trimmed_token[len - 1] == '\t' || trimmed_token[len - 1] == '\n'))
				trimmed_token[--len] = '\0';

			if (len > 0)
			{
				/* Remove spaces before and after instruction */
				instruction = strtok(trimmed_token, " \t\n");
				if (instruction == NULL)
				{
					fprintf(stderr, "L%u: unknown instruction\n", line_num);
					exit(EXIT_FAILURE);
				}
				i = 0;
				while (op[i].opcode)
				{
					if (strcmp(instruction, "push") == 0 &&
						strcmp(instruction, op[i].opcode) == 0)
					{
						arg = strtok(NULL, " \t\n");
					if (arg == NULL)
					{
						fprintf(stderr, "L%u: usage: push integer\n", line_num);
						exit(EXIT_FAILURE);
					}
						/* Check if argument to push is a number */
						value = strtol(arg, &endptr, 10);
					if (*endptr != '\0')
					{
						fprintf(stderr, "L%u: usage: push integer\n", line_num);
						exit(EXIT_FAILURE);
					}

						data = value;
						op[i].f(&stack, line_num);
						break;
					}
					else if (strcmp(instruction, op[i].opcode) == 0)
					{
						op[i].f(&stack, line_num);
						break;
					}
					i++;
				}
				if (op[i].opcode == NULL)
				{
					fprintf(stderr, "L%u: unknown instruction %s\n", line_num, instruction);
					exit(EXIT_FAILURE);
				}
			}
		}
	}

	/* Close the file */
	fclose(file);
	/* Free memory */
	free_stack(stack);
	return (0);
}
