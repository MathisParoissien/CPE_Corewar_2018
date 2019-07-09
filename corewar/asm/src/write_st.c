/*
** EPITECH PROJECT, 2019
** asm
** File description:
** write_st
*/

#include "../include/corewar.h"

int write_st(int fd, char **tab, asm_t *asl)
{
    char m = 0x03;
    int byte = 0;
    int args[2] = {byte_code(tab[1]), byte_code(tab[2])};
    int k = my_getnbr(problem_2(tab[1], 'r'));
    int p = my_getnbr(problem_2(tab[2], 'r'));
    int b = 0;

    UNUSED(asl);
    for (int m = 1; tab[m]; m++)
        byte |= (args[m - 1] << (2 * (4 - m)));
    write(fd, &m, 1);
    write(fd, &byte, 1);
    write(fd, &k, 1);
    if (byte_code(tab[2]) == 1)
        write(fd, &p, 1);
    else {
        p = little_to_big_endian(p);
        b = (p >> 16) | (p << 16);
        write(fd, &b, 2);
    }
    return (0);
}