/*
** EPITECH PROJECT, 2019
** asm
** File description:
** write_sti
*/

#include "../include/corewar.h"

void write_sti_2(char **tab, int fd, asm_t *asl)
{
    int p = coffee(tab[2], asl);
    int k = coffee(tab[3], asl);

    if (byte_code(tab[2]) == 2) {
        p = little_to_big_endian(p);
        p = (p >> 16) | (p << 16);
        write(fd, &p, 2);
    } else if (byte_code(tab[2]) == 3) {
        p = little_to_big_endian(p);
        p = (p >> 16) | (p << 16);
        write(fd, &p, 2);
    } else
        write(fd, &p, 1);
    if (byte_code(tab[3]) == 2) {
        k = little_to_big_endian(k);
        k = (k >> 16) | (k << 16);
        write(fd, &k, 2);
    } else
        write(fd, &k, 1);
}

int write_sti(int fd, char **tab, asm_t *asl)
{
    char m = 0x0B;
    int byte = 0;
    int args[3] = {byte_code(tab[1]), byte_code(tab[2]), byte_code(tab[3])};
    int n = my_getnbr(problem_2(tab[1], 'r'));

    for (int m = 1; tab[m]; m++)
        byte |= (args[m - 1] << (2 * (4 - m)));
    write(fd, &m, 1);
    write(fd, &byte, 1);
    write(fd, &n, 1);
    write_sti_2(tab, fd, asl);
    return (0);
}