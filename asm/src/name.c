/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** name
*/

#include "../include/corewar.h"

int check_bla(char *str)
{
    int i = -1;
    int acco = 0;

    while (str[++i]) {
        if (str[i] == '"')
            acco++;
        if (acco == 2 && (str[i + 1]))
            return (1);
    }
    return (0);
}

int my_tablen(char **tab)
{
    int i = 0;

    while ((tab) && (tab[i]))
        i += 1;
    return (i);
}

int get_name(asm_t *asl)
{
    int i = -1;
    int len = -1;
    char **tab = str_to_wortab(asl->lines[0], ' ');
    char **tablo = NULL;

    while ((tab[++i])) {
        if (my_strcmp(tab[i], ".name") == 0) {
            if (check_bla(asl->lines[0]) != 0)
                print_error("problemo\n", 1);
            tablo = str_to_wortab(asl->lines[0], '"');
            if ((len = my_tablen(tablo)) != 3)
                print_error("syntax error\n", 1);
            if (!(tablo[1]))
                print_error("name null\n", 1);
            if (my_strlen(tablo[1]) > PROG_NAME_LENGTH)
                print_error("Name lenght\n", 1);
            asl->name = tablo[1];
            return (0);
        }
    }print_error("syntax error\n", 1);
    return (-1);
}