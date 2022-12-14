#include "main.h"

/**
 * str_len - fucion
 * @s: variable
 * Return: always
 */
int str_len(char *s)
{
	int c = 0;

	while (s[c] != '\0')
		c++;
	return (c);
}
/**
 * *_strcat - funcion
 * @dest: pointer
 * @src: pointer
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int p;

	for (i = 0; dest[i] != '\0' ; i++)
		;
	for (p = 0; src[p] != '\0' ; p++)
	{
		dest[i] = src[p];
		i++;
	}
	return (dest);
}
/**
 * *_strcmp - the function strcmp
 *@s1: pointer
 *@s2: pointer
 *Return: result
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
/**
 * _calloc - malloc-like function that initializes to '0
 * @nmemb: unsigned int
 * @size: unsigned int
 * Return: always
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *a = NULL;

	if (nmemb)
	{
		if (nmemb == 0 || size == 0)
			return (NULL);
		a = malloc((size * nmemb) + 1);

		if (a == NULL)
		{
			free(a);
			return (NULL);
		}
		for (i = 0; i < (nmemb * size); i++)
		{
			a[i] = 0;
		}
		return (a);
	}
	free(a);
	exit(EXIT_SUCCESS);
}
/**
 *_strcpy - funcion
 * @src: pointer
 * @dest: pointer
 * Return: the copy
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0' ; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
