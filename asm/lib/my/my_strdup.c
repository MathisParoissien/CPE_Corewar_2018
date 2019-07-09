/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    char *res = malloc(sizeof(char) * (len + 1));
    int i = -1;

    while (str[++i])
        res[i] = str[i];
    res[i] = 0;
    return (res);
}