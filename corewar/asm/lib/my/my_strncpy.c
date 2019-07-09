/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strncpy
*/

#include "my.h"

char *my_strncpy(char *s1, const char *s2, size_t n)
{
    char *s = s1;

    while (n > 0 && *s2 != '\0') {
        *s++ = *s2++;
        --n;
    }
    while (n > 0) {
        *s++ = '\0';
        --n;
    }
    return (s1);
}