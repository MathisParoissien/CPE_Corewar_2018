/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strncat
*/

#include "my.h"

char *my_strncat(char *s1, const char *s2, size_t n)
{
    unsigned len1 = my_strlen(s1);
    unsigned len2 = my_strlen(s2);

    if (len2 < n) {
        my_strcpy(&s1[len1], s2);
    } else {
        my_strncpy(&s1[len1], s2, n);
        s1[len1 + n] = '\0';
    }
    return (s1);
}