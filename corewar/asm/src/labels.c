/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** labels
*/

#include "../include/corewar.h"

void *find_label(char *str)
{
    char **tab = str_to_wortab(str, ' ');
    int label = 0;

    if (my_strstr(tab[0], ":")) {
        *my_strstr(tab[0], ":") = 0;
        my_strcat(tab[0], ":");
    }
    if ((tab[0]) && tab[0][my_strlen(tab[0]) - 1] == LABEL_CHAR)
        label++;
    if (label > 0) {
        tab = str_to_wortab(tab[0], LABEL_CHAR);
        return (tab[0]);
    }
    return (0);
}

int same_label(asm_t *asl, char *babel)
{
    int i = -1;

    while (asl->labels && asl->labels[++i]) {
        if (my_strcmp(babel, asl->labels[i]->name) == 0)
            print_error("Multiple definition of the same label.\n", 1);
    }
    return (0);
}

int is_octal(char *mne)
{
    int i = -1;
    char *oct[12] = OCTAL;

    if (!(mne))
        return (-1);
    while (++i < 12) {
        if (my_strcmp(mne, oct[i]) == 0)
            return (0);
    }
    return (-1);
}

int label_idx(asm_t *asl, int p, int len)
{
    int i = 2;
    int prog_size = 0;
    char **tab = NULL;
    int k = 0;
    int m = 0;

    while (asl->lines[++i] && my_strncmp(asl->lines[i], \
    asl->labels[p]->name, len) != 0) {
        tab = my_str_to_word_array_cor(asl->lines[i]);
        m = 0;
        k = 0;
        if (tab[0] && tab[0][my_strlen(tab[0]) - 1] == LABEL_CHAR) {
            k++;
            m++;
        } if ((is_octal(tab[k])) == 0)
            prog_size++;
        if (tab[k] && is_a_mne(tab[k]) == 0)
            prog_size++;
        while (tab[++k])
            prog_size += wima(asl, tab[k], tab[m]);
    }return (prog_size);
}

char *problem_2(char *str, char p)
{
    char *buff = NULL;
    int i = -1;
    int k = -1;
    int ok = 0;

    while (str[++i]) {
        if (str[i] == p) {
            ok++;
            break;
        }
    }
    if (ok != 0) {
        buff = xmalloc(sizeof(char) * my_strlen(str) + 1);
        while (str[++i])
            buff[++k] = str[i];
        buff[k + 1] = '\0';
        return (buff);
    } else
        return (str);
}