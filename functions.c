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
	return (0);
}
char **tokenize(char *str)
{
	char *tkn;
	char **tkns;
	int num = 0;
	int j = 0;

	num = num_count(str);

	tkns = _calloc(num + 1, sizeof(char *));
	if (!tkns)
	{
		return (0);
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
	ptkns = _calloc(pnum + 1, sizeof(char *));
	ptkn = strtok(path, ":");
	while (ptkn)
	{
		ptkns[j] = ptkn;
		ptkn = strtok(NULL, ":");
		j++;
	}
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
			free(path);
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
		free(function), function = NULL;
	}
	free(tkns); tkns = NULL;
	free_all(path);
	free(function);
	return (0);
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
		execve(function[0], function, environ);
		free(tokenbuff);
		free(function[0]), function[0] = NULL;
		exit(EXIT_SUCCESS);
	}
	else
	{
		w = waitpid(p, &wstatus, WUNTRACED | WCONTINUED);

		if (w == -1)
			exit(EXIT_FAILURE);

	}
}
