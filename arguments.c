#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 *main - program to get args from comand line
 *@ac: argumentt counter
 *@av: string array
 *Return: if ok return 0
 */
int main(int ac, char **av)
{
	int a;

	printf("exe name=%s\n",av[0]);

	for (a = 0; av[a] != NULL; a++)
	{
		printf("arg%d=%s\n", a, av[a]);
	}
	return (0);
}
