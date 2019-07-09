/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char const *str);
int my_getnbr(char *str);
void my_put_nbr(int nb);
char *my_strcat(char *s, char *append);
char *my_strncat(char *s1, const char *s2, size_t n);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *s1, const char *s2, size_t n);
char *my_strdup(char *str);
char *my_strndup(char *str, int nb);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(char *s1, char *s2, int n);
char **str_to_wortab(char *str, char del);
char *get_next_line(const int fd);

#define UNUSED(x) (void)(x)

#endif /* !MY_H_ */
