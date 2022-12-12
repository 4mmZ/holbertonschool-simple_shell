#include "main.h"

int num_count (char *var)
{
	int count = 0;
	char *aux;
	char *dup = strdup(var);



	aux = strtok(dup, ": 	\n");
	while (aux)
	{
		aux = strtok(NULL, ":    \n");
		count++;
	}
	free(dup);	
	return (count);

	
}
int free_all(char **buffer)
{
	int i = 0;

	if(!buffer)
		return(0);

	for (; i < 0; i++)
		free(buffer[i]);
	free (buffer);
	return(0);
}
