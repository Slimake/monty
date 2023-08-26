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
	int i;
	char *arg1;
	char *arg2;
	FILE *file;
	char line_buf[1024];
	stack_t *stack = NULL;
	unsigned int line_num = 0;
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
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

	/* Read monty bytecodes from file line by line */
	while (fgets(line_buf, sizeof(line_buf), file))
	{
		/* Increment line number on each line */
		line_num++;
		/* get the first */
		arg1 = strtok(line_buf, "$ \t\r\a\n;:");
		if (arg1)
		{
			if (strcmp(arg1, "push") == 0)
			{
				arg2 = strtok(NULL, "$ \t\r\a\n;:");
				if (arg2 == NULL || !isdigit(arg2[0]))
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_num);
					exit(EXIT_FAILURE);
				}
				data = atoi(arg2);
			}

			i = 0;
			while (op[i].opcode)
			{
				if (strcmp(op[i].opcode, arg1) == 0)
				{
					op[i].f(&stack, line_num);
					break;
				}
				i++;
			}
			if (op[i].opcode == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_num, arg1);
				exit(EXIT_FAILURE);
			}
		}
	}

	fclose(file);
	return (0);
}
