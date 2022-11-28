#include "main.h"

int main(int ac, char **argv){
	char *prompt = "root $ ";
	char *lineptr;
	size_t a = 0;

	(void)ac; (void)argv;

	printf("%s", prompt);
	getline(&lineptr, &a, stdin);
	printf("%s\n", lineptr);
	free(lineptr);
	return (0);
}
