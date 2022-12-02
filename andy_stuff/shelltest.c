#include "main.h"
char ** tokenize(char *str);
char ** _path(void);
char ** get_command(char ** tkns);
void execute(char ** function);

int main(void)
{
	char * buffer = NULL;
	size_t i = 0;
	char ** tokenbuff = NULL;
	char ** function;

	while(1)
	{
		printf("SNA$");

		if(getline(&buffer, &i, stdin) == -1)
			return(0);
		tokenbuff = tokenize(buffer);
		function = get_command(tokenbuff);
		execute(function);
	}
}

char ** tokenize(char *str)
{
	char *tkn;
	char ** tkns;
	int i = 1024;
	int j = 0;

	tkns = malloc(sizeof(char *) * i);
	tkn = strtok(str, " \n");
	while (tkn)
	{
		tkns[j] = tkn;
		tkn = strtok(NULL, " \n");
		j++;
	}
	return (tkns);
}
char ** _path(void)
{
	char *path = getenv("PATH");
	char *ptkn;
	char **ptkns;
	int i = 1024;
	int j = 0;

	ptkns = malloc(sizeof(char *) * i);
	ptkn = strtok(path, ":");

	while (ptkn)
	{
		ptkns[j] = ptkn;
		ptkn = strtok(NULL, ":");
		j++;
	}
	return (ptkns);
}
char ** get_command(char ** tkns)
{
	 char * ccopy;
	 char ** path = _path();
	 char * function;
	 int i = 0;

	 while(path[i])
	 {
		ccopy = tkns[0];
		function = malloc(strlen(path[i]) + strlen(ccopy) + 1);
	       strcpy(function, path[i]);
	       strcat(function, "/");
	       strcat(function, ccopy);
	       i++;
	 }
	 tkns[0] = function;
	 return (tkns);
}
void execute(char ** function)
{
	execve(function[0], function, NULL);
}

