#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char ** environ;

int num_count (char *var);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int str_len(char *s);
char **tokenize(char *str);
char **_path(void);
char **get_command(char **tkns);
void execute(char **tokenbuff);
char * get_env(char * variable);
#endif
