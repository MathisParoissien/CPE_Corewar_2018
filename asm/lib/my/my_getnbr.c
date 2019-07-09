/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr(char *str)
{
    int c = 0;
    int i = 0;

    if (str[0] == '-') {
        c = (c * (-1));
        i += 1;
    } else if (str[i] < '0' || str[i] > '9')
        return (0);
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        c = c * 10 + (str[i] - '0');
        i += 1;
    } if (str[0] == '-')
        c = (c * (-1));
    return (c);
}