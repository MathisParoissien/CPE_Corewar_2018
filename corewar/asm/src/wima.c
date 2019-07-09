/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** wima
*/

#include "../include/corewar.h"

int is_a_mne(char *str)
{
    int i = -1;

    if (!(str))
        return (84);
    while (op_tab[++i].mnemonique && \
    my_strcmp(str, op_tab[i].mnemonique) != 0);
    if (i >= 16) {
        return (1);
    }
    else {
        return (0);
    }
}

int wima(asm_t *asl, char *str, char *mne)
{
    UNUSED(asl);
    if (!(str) || my_strcmp(str, "") == 0)
        return (0);
    if (str[0] == 'r')
        return (T_REG);
    else if (str[0] == DIRECT_CHAR)
        return ((EX) ? 2 : DIR_SIZE);
    else
        return (T_IND);
}