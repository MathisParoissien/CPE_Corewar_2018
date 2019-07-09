/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_putstr
*/

#include "my.h"

void my_putstr(char *str)
{
    int i = -1;

    while (str[++i])
        my_putchar(str[i]);
}