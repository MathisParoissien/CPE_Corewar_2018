/*
** EPITECH PROJECT, 2019
** erg
** File description:
** zeg
*/

#include "../include/corewar.h"

int find_nb_of_words_cor(char const *str)
{
    int i = 0;
    int nb_words = 0;

    while (str[i] != '\0' && (str[i] == ' ' || str[i] == SEPARATOR_CHAR))
        i = i + 1;
    while (str[i] != '\0') {
        if ((str[i] == ' ' || str[i] == SEPARATOR_CHAR)
        && str[i - 1] != ' ' && str[i - 1] != SEPARATOR_CHAR)
            nb_words = nb_words + 1;
        i = i + 1;
    }
    if (str[i - 1] != ' ' && str[i - 1] != SEPARATOR_CHAR)
        nb_words = nb_words + 1;
    return (nb_words);
}

char *set_line_space_cor(char const *str, int *c)
{
    int i = *c;
    int t = *c;
    char *line;

    while (str[t] != '\0' && str[t] != ' ' && str[t] != SEPARATOR_CHAR)
        t = t + 1;
    line = malloc(sizeof(char) * (t - i + 1));
    for (int f = 0; f < (t - i + 1); f = f + 1)
        line[f] = '\0';
    for (int h = 0; i < t; h = h + 1) {
        line[h] = str[i];
        i = i + 1;
    }
    *c = i;
    return (line);
}

char **my_str_to_word_array_cor(char const *str)
{
    int i = 0;
    int nb_words = find_nb_of_words_cor(str);
    char **stock = malloc(sizeof(char *) * (nb_words + 1));

    while (str[i] != '\0' && (str[i] == ' ' || str[i] == SEPARATOR_CHAR))
        i = i + 1;
    for (int j = 0; j < nb_words; j = j + 1) {
        stock[j] = set_line_space_cor(str, &i);
        while (str[i] != '\0' && (str[i] == ' ' || str[i] == SEPARATOR_CHAR))
            i = i + 1;
    }
    stock[nb_words] = NULL;
    return (stock);
}
