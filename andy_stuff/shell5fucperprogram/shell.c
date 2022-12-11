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
		printf("SNA$ ");
		if (getline(&buffer, &i, stdin) == -1)
			return (0);
		tokenbuff = tokenize(buffer);
		execute(tokenbuff);

		if (strcmp(buffer, "exit") == 0)
		{
			return (0);
		}
	}
	free(tokenbuff);
}
/*
void prompt (int entero)
{
	printf("SNA$");
}*/
