#include "main.h"

char *get_env(char *variable)
{
	char **env = environ;
	int x = 0, y, con = 0, len;
	char *path = NULL;

	path = variable;
	if (variable == NULL || !variable[x])
		return (NULL);
	len = str_len(path);
	while (*(environ + x))
	{
		y = 0;
		while (*(*(env + x) + y) != '=')
		{
			if (*(*(env + x) + y) == variable[y])
				con++;
			y++;
		}
		if (con == len)
		{
			y++;
			return (*(environ + x) + y);
		}
		x++;
		con = 0;
	}
	free(path);
	return (NULL);
}
char **tokenize(char *str)
{
	char *tkn;
	char **tkns;
	int num = 0;
	int j = 0;

	num = num_count(str);

	tkns = calloc(num + 1, sizeof(char *));
	if (!tkns)
	{
		free(tkns);
		return(NULL);
	}
	tkn = strtok(str, "	 \n");
	while (tkn)
	{
		tkns[j] = tkn;
		tkn = strtok(NULL, "	 \n");
		j++;
	}
	
	return (tkns);

}
char **_path(void)
{
	char *path = get_env("PATH");
	char *ptkn;
	char **ptkns;
	int pnum = 0;
	int j = 0;

	pnum = num_count(path);
	ptkns = calloc(pnum + 1, sizeof(char *));
	ptkn = strtok(path, ":");
	if (!ptkns)
		return(0);

	while (ptkn)
	{
		ptkns[j] = ptkn;
		ptkn = strtok(NULL, ":");
		j++;
	}
	free(ptkn);
	return (ptkns);
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
		function = _calloc(str_len(path[i]) + str_len(ccopy) + 2, sizeof(char));
		if (!function)
		{
			perror("Error");
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
	free(function);
	return (tkns);
}
void execute(char **tokenbuff)
{
	pid_t p, w;
	char **function;

	int wstatus;

	p = fork();

	if (p == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (p == 0)
	{
		function = get_command(tokenbuff);
		if(execve(function[0], function, environ) == 1)
			exit(0);
		exit(0);
	}
	else
	{
		w = waitpid(p, &wstatus, WUNTRACED | WCONTINUED);

		if (w == -1)
			exit(EXIT_FAILURE);

	}
}
