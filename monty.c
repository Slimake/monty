#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
#define LIMIT 100

/**
 * monty - interpretes MontyByteCodes files
 * @argc: command-line argument counter
 * @argv: command-line arguments
 *
 * Return: nothing
 */

void monty(int argc, char **argv)
{
	char line[LIMIT];
	char *filename = argv[1];
	char *arg;

	FILE *fp;

	unsigned int line_num= 0;

	/* Check if argc is not equal to 2 */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Read from file */
	fp = fopen(filename, "r");
	if (fp == NULL) /* Check if fopen return NULL */
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	/* Get each line in the file */
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		line_num++;
		/* Get words in each line */
		arg = strtok(line, " ");
		/* If args is push call push() */
		if (strcmp(arg, "push") == 0)
		{
			while (arg != NULL)
			{
				arg = strtok(NULL, " ");
				break;
			}
			/* Check if push has no argument or argument is not an integer */ 
			if (arg == NULL || (!atoi(arg)))
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_num);
				/*exit(EXIT_FAILURE);*/
			}
			/* If arg is an integer, call push function*/
			if (atoi(arg))
				push(atoi(arg));
		}
		/* If args is pall call pall() */
		else if (strcmp(arg, "pall") == 0)
		{
			pall();
		}
		else if (strcmp(arg, "pint") == 0)
		{
			pint(line_num);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s", line_num, arg);
			/*exit(EXIT_FAILURE);*/
		}
	}
	fclose(fp);
}
