#include "main.h"

char * get_env(char * variable)
{
        char ** env = environ;
        char *path = NULL;
	int i;

        for ( i = 0; env[i]; i++)
        {
                path = strtok(env[i], "=");
                if (!strcmp(path, variable))
                        return(strtok(NULL, "="));
        }
	free(path);
        return (NULL);
}

char **tokenize(char *str)
{
	char *tkn;
	char **tkns;
	int i = 1024;
	int j = 0;

	tkns = malloc(sizeof(char *) * i);
	tkn = strtok(str, "	 \n");
	while (tkn)
	{
		tkns[j] = tkn;
		tkn = strtok(NULL, " \n");
		j++;
	}
	return (tkns);
	free(tkns);
}
char **_path(void)
{
	char *path = get_env("PATH");
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
	free(ptkns);
}
char **get_command(char **tkns)
{
	 char *ccopy;
	 char **path = _path();
	 char *function = NULL;
	 int i = 0;
	 struct stat buf;

	while (path[i])
	{
		ccopy = tkns[0];
		function = malloc(str_len(path[i]) + str_len(ccopy) + 1);
		if (!function)
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
			return (tkns);
		}
		i++;
	}
	return (tkns);
	free(tkns);
}
void execute(char **tokenbuff)
{
	pid_t p, w;
	char **function;

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
		execve(function[0], function, environ);
		exit(0);
	}
	else
	{
		w = waitpid(p, &wstatus, WUNTRACED | WCONTINUED);

		if (w == -1)
			exit(EXIT_FAILURE);

	}
}
