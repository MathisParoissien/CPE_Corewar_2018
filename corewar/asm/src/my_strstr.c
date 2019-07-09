/*
** EPITECH PROJECT, 2019
** asm
** File description:
** my_strstr
*/

#include "../include/corewar.h"

char *my_strchr(char *p, int ch)
{
    char c;

    c = ch;
    for (;; ++p) {
        if (*p == c)
            return ((char *)p);
        if (*p == '\0')
            return (NULL);
    }
}

char *my_strstr(char *s1, char *s2)
{
    char *p = s1;
    size_t len = my_strlen(s2);

    for (; (p = my_strchr(p, *s2)) != 0; p++) {
        if (my_strncmp(p, s2, len) == 0)
            return (char *)p;
    }
    return (0);
}