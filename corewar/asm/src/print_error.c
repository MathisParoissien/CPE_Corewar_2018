/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** print_error
*/

#include "../include/corewar.h"

static void print_error(char *error, const bool critical)
{
    my_putstr(error);
    if (critical)
        exit(84);
}