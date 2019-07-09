/*
** EPITECH PROJECT, 2019
** asm
** File description:
** check_label
*/

#include "../include/corewar.h"

int is_digit(char *str)
{
    int i = -1;

    while (str[++i])
        if ((str[i] > '9' || str[i] < '0') && str[i] != '-')
            return (-1);
    return (0);
}

void norme(char *str)
{
    if (is_digit(str) != 0)
        print_error("bad label\n", 1);
}

void check_dir(char *str, asm_t *asl)
{
    char **tab = NULL;

    if (str[0] == DIRECT_CHAR) {
        if (str[1] == LABEL_CHAR) {
            tab = str_to_wortab(str, LABEL_CHAR);
            is_label(asl, tab[1]);
        } else {
            tab = str_to_wortab(str, DIRECT_CHAR);
            norme(tab[1]);
        }
    }
}

void check_labels(asm_t *asl)
{
    int i = -1;
    char **tab = NULL;
    int k = -1;

    while (asl->labels[++i]) {
        if (check_char(asl->labels[i]->name) != 0)
            print_error("bad label char\n", 1);
    }
    i = -1;
    while (asl->lines[++i]) {
        k = -1;
        tab = my_str_to_word_array_cor(asl->lines[i]);
        while (tab[++k]) {
            check_dir(tab[k], asl);
        }
    }
}