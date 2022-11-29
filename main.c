#include "main.h"
/**
 *
 *gcc -Wall -Wextra -Werror -pedantic main.c
 *
 */
int main(int ac, char **argv){
	char *prompt = "andy $ ";
	char *lineptr = NULL;/*Almacena la direccion del buf*/
	char *lineptr_copy = NULL;/*Copia de LINEPTR*/
	size_t a = 0;/*Almacena el tamaño asignado en bytes*/
	ssize_t chars_read;/*al ser -1 sale de la shell*/
	const char *elim = " \n";

	/*Variables nulasxd*/
	(void)ac; (void)argv;

	/*loop infinito*/
	while(1)
	{
		printf("%s", prompt);
		chars_read = getline(&lineptr, &a, stdin);
		if (chars_read == -1)
		{
			printf("goodbye shell...\n");/**Ctrl D salida shell*/
			return (-1);
		}
		printf("%s\n", lineptr);
	}
	/*Liberar memoria asignada*/
	free(lineptr);
	return (0);
}
