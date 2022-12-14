#include "main.h"

/**
 * main - basic shell proyect: a Unix command interpreter;
 * Return: 0
 */

int main(void)
{
	char *buffer = NULL;
	size_t i = 0;
	char **tokenbuff;
	int line = 0;

	while (1)
	{
		if (isatty(0) == 1)
			printf("$ ");
		line = getline(&buffer, &i, stdin);
		if (line == -1)
		{
			free(buffer);
			exit(0);
		}
		tokenbuff = tokenize(buffer);
		if (tokenbuff == NULL)
		{
			free_all(tokenbuff);
			exit(0);
		}
		execute(tokenbuff);
		free(tokenbuff), tokenbuff = NULL;
		/*free_all(tokenbuff);*/
		if (_strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			return (0);
		}
	}
	free_all(tokenbuff);
	exit(EXIT_SUCCESS);
	return (0);
}
