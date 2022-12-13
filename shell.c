#include "main.h"

/*void prompt (int entero);*/

int main(void)
{
	char *buffer = NULL;
	size_t i = 0;
	char **tokenbuff;
	int line = 0;
	/*signal(SIGINT, prompt);*/
	while (1)
	{
		if (isatty(0) == 1)
			printf("$ ");
		line = getline(&buffer, &i, stdin);
		if (line == -1)
		{
			free(buffer);
			exit (0);
		
		}
		tokenbuff = tokenize(buffer);
		if (tokenbuff == NULL)
		{
			free_all(tokenbuff);
			exit(0);
		}
		execute(tokenbuff);
		/*free_all(tokenbuff);*/
		if (_strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit (EXIT_SUCCESS);
		}
	}
	free(buffer);
	free(tokenbuff);
	exit(0);
}
/*
void prompt (int entero)
{
	printf("SNA$");
}*/
