/*
** EPITECH PROJECT, 2019
** asm
** File description:
** write_add
*/

#include "../include/corewar.h"

int write_add(int fd, char **tab, asm_t *asl)
{
    char m = 0x04;
    int byte = 0;
    int args[3] = {byte_code(tab[1]), byte_code(tab[2]), byte_code(tab[3])};
    int k = my_getnbr(problem_2(tab[1], 'r'));
    int p = my_getnbr(problem_2(tab[2], 'r'));
    int n = my_getnbr(problem_2(tab[3], 'r'));

    UNUSED(asl);
    for (int m = 1; tab[m]; m++)
        byte |= (args[m - 1] << (2 * (4 - m)));
    write(fd, &m, 1);
    write(fd, &byte, 1);
    write(fd, &k, 1);
    write(fd, &p, 1);
    write(fd, &n, 1);
    return (0);
}

int write_sub(int fd, char **tab, asm_t *asl)
{
    char m = 0x05;
    int byte = 0;
    int args[3] = {byte_code(tab[1]), byte_code(tab[2]), byte_code(tab[3])};
    int k = my_getnbr(problem_2(tab[1], 'r'));
    int p = my_getnbr(problem_2(tab[2], 'r'));
    int n = my_getnbr(problem_2(tab[3], 'r'));

    UNUSED(asl);
    for (int m = 1; tab[m]; m++)
        byte |= (args[m - 1] << (2 * (4 - m)));
    write(fd, &m, 1);
    write(fd, &byte, 1);
    write(fd, &k, 1);
    write(fd, &p, 1);
    write(fd, &n, 1);
    return (0);
}