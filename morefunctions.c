#include "main.h"

/**
 * function that receives a string and recorres with a counter
 * and returns the counter.
 * @var: the variable that  want to recorre.
 * return: the counter;
 */
int num_count(char *var)
{
	int count = 0;
	char *aux;
	char *dup = strdup(var);

	aux = strtok(dup, " :	\n");
	while (aux)
	{
		aux = strtok(NULL, ":    \n");
		count++;
	}
	free(dup);
	return (count);


}
/**
 * free_all - function that frees an entire string.
 * @buffer: the string that i want to frees.
 * Return: 0
 */
int free_all(char **buffer)
{
	int i = 0;

	if (!buffer)
		return (0);

	for (; i < 0; i++)
		free(buffer[i]);
	free(buffer), buffer = NULL;
	return (0);
}
