/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** init
*/

#include "../include/corewar.h"

void init_function(asm_t *asl)
{
    asl->prog_size = 0;
    asl->labels = NULL;
    asl->index_core = 0;
    asl->fd = 0;
    asl->cor = xmalloc(sizeof(char) * 4096);
}

void free_function(asm_t *asl)
{
    free(asl->lines);
    free(asl->cor);
    free(asl);
}