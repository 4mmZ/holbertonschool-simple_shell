#include "main.h"

/*void prompt (int entero);*/

int main(void)
{
	char *buffer = NULL;
	size_t i = 0;
	char **tokenbuff;
	/*signal(SIGINT, prompt);*/
	while (1)
	{
		if (isatty(0) == 1)
			printf("SNA$ ");
		if (getline(&buffer, &i, stdin) == -1)
		{
			free(buffer);
			return (0);
		
		}
		tokenbuff = tokenize(buffer);
		execute(tokenbuff);
		free(tokenbuff);

		if (_strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			return (0);
		}
	}
	free(buffer);
	free(tokenbuff);
}
/*
void prompt (int entero)
{
	printf("SNA$");
}*/
