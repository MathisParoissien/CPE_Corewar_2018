/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = -1;

    if (!str)
        return (0);
    while (str[++i]);
    return (i);
}