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
			return(0);
		}
	}
	free_all(tokenbuff);
	exit(EXIT_SUCCESS);
}
