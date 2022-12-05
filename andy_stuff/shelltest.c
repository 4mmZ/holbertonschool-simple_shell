#include "main.h"
char ** tokenize(char *str);
char ** _path(void);
char ** get_command(char ** tkns);
void execute(char ** function, char ** tokenbuff);

int main(void)
{
	char * buffer = NULL;
	size_t i = 0;
	char ** function;
	char ** tokenbuff;
	while (1)
	{	
		printf("SNA$");
		if(getline(&buffer, &i, stdin) == -1)
			return(0);
		tokenbuff = tokenize(buffer);
		execute(function, tokenbuff);
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
	 char * function = NULL;
	 int i = 0;
	 struct stat buf;

	 while(path[i])
	 {
		ccopy = tkns[0];
		function = malloc(strlen(path[i]) + strlen(ccopy) + 1);
		if(!function)
		{
			perror("nashe");
			exit(EXIT_FAILURE);
		}
		strcpy(function, path[i]);
		strcat(function, "/");
		strcat(function, ccopy);
		if (!stat(function, &buf))
		{
		       tkns[0] = function;
		       return(tkns);
		}
		i++;
	}
	return (tkns);
}
void execute(char ** function, char ** tokenbuff)
{
	char * buff = NULL;
	pid_t p, w;
	char command = 0;

	int wstatus;

	p = fork();

	if (p == -1)
	{
		perror("nashe");
		exit(EXIT_FAILURE);
	}
	else if (p == 0)
	{
		function = get_command(tokenbuff);
		command = execve(function[0], function, NULL);
		exit(0);
	}
	else
	{
		w = waitpid(p, &wstatus, WUNTRACED | WCONTINUED);

		if (w == -1)
			exit(EXIT_FAILURE);

	}
}
