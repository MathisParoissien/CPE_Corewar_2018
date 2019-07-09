/*
** EPITECH PROJECT, 2019
** asm
** File description:
** opcode
*/

#include "../include/corewar.h"

int check_args(int mne, char **tab)
{
    int len = -1;

    while (tab[++len]);
    len = len - 1;
    if (len != op_tab[mne].nbr_args)
        return (84);
    return (0);
}

int what_is_my_arg(char *str, int i, int j, asm_t *asl)
{
    if ((op_tab[i].type[j - 1] & T_REG) == T_REG && str[0] == 'r') {
        asl->prog_size += T_REG;
        return (0);
    }
    if ((op_tab[i].type[j - 1] & T_DIR) == T_DIR && str[0] == DIRECT_CHAR) {
        asl->prog_size += (EXEPTION) ? 2 : DIR_SIZE;
        return (0);
    }
    if ((op_tab[i].type[j- 1] & T_IND) == T_IND) {
        asl->prog_size += IND_SIZE;
        return (0);
    }
    print_error("bad argument\n", 1);
    return (0);
}

void check_op(char *str, asm_t *asl)
{
    char **tab = my_str_to_word_array_cor(str);
    int i = -1;
    int j = 0;
    int len = -1;

    if (tab[0] && tab[0][0] != '\0') {
        while (op_tab[++i].mnemonique && \
        my_strcmp(tab[0], op_tab[i].mnemonique));
        if (tab[0][my_strlen(tab[0]) - 1] != LABEL_CHAR && i >= 16) {
            print_error("Invalid instruction\n", 1);
        }
        if (check_args(i, tab) != 0)
            print_error("arguments invalid\n", 1);
        while (tab[++len]);
        len = len - 1;
        asl->prog_size += (MNEUMONIQUE) ? 1 : 2;
        while (tab[++j] && j <= len)
            what_is_my_arg(tab[j], i, j, asl);
    }
}

char **delete_f(char **tab)
{
    char **res = NULL;
    int i = 0;
    int k = -1;
    int len = -1;

    while (tab[++len]);
    res = xmalloc(sizeof(char *) * len + 1);
    while (tab[++i]) {
        res[++k] = xmalloc(sizeof(char) * my_strlen(tab[i]) + 1);
        res[k] = my_strdup(tab[i]);
        res[k][my_strlen(tab[i]) + 1] = '\0';
    }
    tab[k + 1] = NULL;
    return (res);
}

void check_opcode(asm_t *asl)
{
    int i = 2;
    char **tab = NULL;

    while ((asl->lines[++i])) {
        tab = my_str_to_word_array_cor(asl->lines[i]);
        if (tab[0] && tab[0][my_strlen(tab[0]) - 1] == LABEL_CHAR) {
            check_op(problem_2(asl->lines[i], ':'), asl);
        }
        else if (tab[0]) {
            check_op(asl->lines[i], asl);
        }
    }
}