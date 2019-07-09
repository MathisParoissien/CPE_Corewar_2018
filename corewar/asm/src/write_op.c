/*
** EPITECH PROJECT, 2019
** asm
** File description:
** write_op
*/

#include "../include/corewar.h"

char *problem_3(char *str, char p, char s)
{
    char *buff = NULL;
    int i = -1;
    int k = -1;
    int ok = 0;

    while (str[++i]) {
        if (str[i] == p || str[i] == s) {
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

int is_lab(char *str, asm_t *asl)
{
    int i = 0;
    int len = -1;

    if ((asl->labels[0])) {
        while ((asl->labels[++len]));
        while ((asl->labels[i])) {
            if (asl->labels[i]->name && my_strncmp(str, \
            asl->labels[i]->name, my_strlen(str)) == 0)
                return (i);
            i++;
        }
        return (-84);
    }
    return (-84);
}

int calc_lab(asm_t *asl, int idx)
{
    int lab_size = 0;
    int i = 2;
    char **tab = NULL;
    int k = 0;
    NORME

    while (asl->lines[++i] && i < asl->index_core) {
        tab = my_str_to_word_array_cor(asl->lines[i]);
        hihi
        if (tab[0] && tab[0][my_strlen(tab[0]) - 1] == LABEL_CHAR) {
            haha
        } if ((is_octal(tab[d])) == 0)
            lab_size++;
        if (is_a_mne(tab[d]) == 0)
            lab_size++;
        while (tab[++k]) {
            lab_size += wima(asl, tab[k], tab[d]);
        }
    } return ((asl->labels[idx]->prog_idx) - (lab_size));
}

int coffee(char *str, asm_t *asl)
{
    int lab = 0;

    if (str[0] == DIRECT_CHAR || str[0] == 'r') {
        str = problem_3(str, DIRECT_CHAR, 'r');
        str = problem_2(str, LABEL_CHAR);
    }
    if (my_strcmp(str, "") == 0)
        print_error("bad argument", 1);
    if (asl->there_is_a_lab > 0 && (lab = is_lab(str, asl)) != -84)
        return (calc_lab(asl, lab));
    else
        return (my_getnbr(str));
}

int write_live(int fd, char **tab, asm_t *asl)
{
    char m = 0x01;
    int k = little_to_big_endian(coffee(tab[1], asl));

    write(fd, &m, 1);
    write(fd, &k, 4);
    return (0);
}