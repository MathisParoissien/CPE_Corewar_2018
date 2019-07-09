/*
** EPITECH PROJECT, 2019
** asm
** File description:
** write_zjmp
*/

#include "../include/corewar.h"

int write_zjmp(int fd, char **tab, asm_t *asl)
{
    char m = 0x09;
    int k = coffee(tab[1], asl);
    int b = 0;

    k = little_to_big_endian(k);
    b = (k >> 16) | (k << 16);
    write(fd, &m, 1);
    write(fd, &b, 2);
    return (0);
}

int write_fork(int fd, char **tab, asm_t *asl)
{
    char m = 0x0C;
    int k = coffee(tab[1], asl);
    int b = 0;

    k = little_to_big_endian(k);
    b = (k >> 16) | (k << 16);
    write(fd, &m, 1);
    write(fd, &b, 2);
    return (0);
}

int write_lfork(int fd, char **tab, asm_t *asl)
{
    char m = 0x0F;
    int k = coffee(tab[1], asl);
    int b = 0;

    k = little_to_big_endian(k);
    b = (k >> 16) | (k << 16);
    write(fd, &m, 1);
    write(fd, &b, 2);
    return (0);
}

int write_aff(int fd, char **tab, asm_t *asl)
{
    char m = 0x10;
    int k = my_getnbr(problem_2(tab[1], 'r'));
    int b = 64;

    UNUSED(asl);
    write(fd, &m, 1);
    write(fd, &b, 1);
    write(fd, &k, T_REG);
    return (0);
}