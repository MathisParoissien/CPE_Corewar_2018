/*
** EPITECH PROJECT, 2019
** asm
** File description:
** check_label_2
*/

#include "../include/corewar.h"

void check_reg_number(char *str)
{
    char **tab = str_to_wortab(str, 'r');
    int k = 0;

    if (tab[1])
        k = my_getnbr(tab[1]);
    if (k < 1 || k > REG_NUMBER)
        print_error("error register\n", 1);
}

void check_register(asm_t *asl)
{
    int i = 1;
    int k = -1;
    char **tab = NULL;

    while (asl->lines[++i]) {
        tab = my_str_to_word_array_cor(asl->lines[i]);
        k = -1;
        while (tab[++k]) {
            if (tab[k][0] == 'r')
                check_reg_number(tab[k]);
        }
    }
}

int check_char(char *str)
{
    int i = -1;
    int k = -1;
    int ok = 0;

    while (str[++i]) {
        k = -1;
        while (LABEL_CHARS[++k]) {
            if (str[i] == LABEL_CHARS[k])
                ok++;
        }
    }
    if (ok != my_strlen(str))
        return (-1);
    return (0);
}

int is_label(asm_t *asl, char *babel)
{
    int i = -1;

    while (asl->labels && asl->labels[++i]) {
        if (my_strcmp(babel, asl->labels[i]->name) == 0)
            return (1);
    }
    print_error("bad label\n", 1);
    return (0);
}