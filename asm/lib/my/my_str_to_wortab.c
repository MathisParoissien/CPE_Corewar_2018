/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_str_to_wortab
*/

#include "my.h"

int count_letter(char *str, char del)
{
    int i = -1;
    int letter = 0;

    while ((str[++i])&& str[i] != del)
        letter++;
    return (letter);
}

int count_sep(char *str, char del)
{
    int i = -1;
    int count = 0;

    while ((str[++i])) {
        if (str[i] == del)
            count++;
    }
    count++;
    return (count);
}

char **str_to_wortab(char *str, char del)
{
    char **tab = NULL;
    int sep = count_sep(str, del);
    int i = -1;
    char *tmp = my_strndup(str, my_strlen(str));

    tab = malloc(sizeof(char *) * (sep + 2));
    while (++i < sep) {
        tab[i] = my_strndup(tmp, count_letter(tmp, del));
        tmp = &tmp[count_letter(tmp, del) + 1];
    }
    tab[sep + 1] = NULL;
    return (tab);
}