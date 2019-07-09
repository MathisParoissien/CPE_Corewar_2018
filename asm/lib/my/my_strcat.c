/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *s, char *append)
{
    char *save = s;

    for (; *s; ++s);
    while ((*s++ = *append++));
    return (save);
}