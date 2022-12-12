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
