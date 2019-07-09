/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** xmalloc
*/

#include "../include/corewar.h"

void print_error(char *error, bool critical)
{
    my_putstr(error);
    if (critical)
        exit(84);
}

void *xmalloc(const size_t size)
{
    void *p;

    p = malloc(size);
    if (p == NULL)
        print_error("malloc error\n", 1);
    return (p);
}