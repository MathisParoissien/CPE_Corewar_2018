/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** comment
*/

#include "../include/corewar.h"

int get_comment(asm_t *asl)
{
    int i = -1;
    int len = -1;
    char **tab = str_to_wortab(asl->lines[1], ' ');
    char **tablo = NULL;

    while ((tab[++i])) {
        if (my_strcmp(tab[i], ".comment") == 0) {
            if (check_bla(asl->lines[1]) != 0)
                print_error("problemo\n", 1);
            tablo = str_to_wortab(asl->lines[1], '"');
            if ((len = my_tablen(tablo)) != 3)
                print_error("syntax error\n", 1);
            if (!(tablo[1]) || (my_strlen(tablo[1])) > COMMENT_LENGTH)
                print_error("problem\n", 1);
            asl->comment = tablo[1];
            return (0);
        }
    }print_error("syntax error\n", 1);
    return (-1);
}