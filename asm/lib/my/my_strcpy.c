/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char *s1, char const *s2)
{
    char *s = s1;

    while ((*s++ = *s2++) != 0);
    return (s1);
}