/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strndup
*/

#include "my.h"

char *my_strndup(char *str, int nb)
{
    int len = my_strlen(str);
    char *res = malloc(sizeof(char) * (nb + 1));
    int i = -1;

    while (++i != nb) {
        res[i] = str[i];
    }
    res[i] = 0;
    return (res);
}