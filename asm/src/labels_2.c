/*
** EPITECH PROJECT, 2019
** asm
** File description:
** labels_2
*/

#include "../include/corewar.h"

int add_label(asm_t *asl, char *str)
{
    static int p = -1;
    asl->labels[++p] = xmalloc(sizeof(label_t));

    asl->labels[p]->name = str;
    asl->labels[p]->prog_idx = label_idx(asl, p, my_strlen(str));
    return (p);
}

void get_labels(asm_t *asl)
{
    int i = -1;
    int nb_lab = 0;
    int p = 0;

    asl->there_is_a_lab = 0;
    while (asl->lines[++i]) {
        if (find_label(asl->lines[i]) != 0)
            nb_lab++;
    } if (nb_lab > 0) {
        asl->labels = xmalloc(sizeof(label_t) * nb_lab + 1);
        asl->there_is_a_lab = 1;
        i = -1;
        while (asl->lines[++i]) {
            if (find_label(asl->lines[i]) != 0 && \
            same_label(asl, find_label(asl->lines[i])) == 0) {
                p = add_label(asl, find_label(asl->lines[i]));
            }
        }
        asl->labels[p + 1] = NULL;
    }
}