/*
** EPITECH PROJECT, 2019
** asm
** File description:
** write_or
*/

#include "../include/corewar.h"

void write_or_or(int fd, char **tab, asm_t *asl, int b)
{
    int k = coffee(tab[1], asl);
    int p = coffee(tab[2], asl);

    if (byte_code(tab[1]) == 2) {
        k = little_to_big_endian(k);
        write(fd, &k, 4);
    } else if (byte_code(tab[1]) == 3) {
        k = little_to_big_endian(k);
        b = (k >> 16) | (k << 16);
        write(fd, &b, 2);
    } else
        write(fd, &k, 1);
    if (byte_code(tab[2]) == 2) {
        p = little_to_big_endian(p);
        write(fd, &p, 4);
    } else if (byte_code(tab[2]) == 3) {
        p = little_to_big_endian(p);
        b = (p >> 16) | (p << 16);
        write(fd, &b, 2);
    } else
        write(fd, &p, 1);
}

int write_or(int fd, char **tab, asm_t *asl)
{
    char m = 0x07;
    int byte = 0;
    int args[3] = {byte_code(tab[1]), byte_code(tab[2]), byte_code(tab[3])};
    int n = my_getnbr(problem_2(tab[3], 'r'));
    int b = 0;

    for (int m = 1; tab[m]; m++)
        byte |= (args[m - 1] << (2 * (4 - m)));
    write(fd, &m, 1);
    write(fd, &byte, 1);
    write_or_or(fd, tab, asl, b);
    write(fd, &n, 1);
    return (0);
}

void write_xor_xor(int fd, char **tab, asm_t *asl, int b)
{
    int k = coffee(tab[1], asl);
    int p = coffee(tab[2], asl);

    if (byte_code(tab[1]) == 2) {
        k = little_to_big_endian(k);
        write(fd, &k, 4);
    } else if (byte_code(tab[1]) == 3) {
        k = little_to_big_endian(k);
        b = (k >> 16) | (k << 16);
        write(fd, &b, 2);
    } else
        write(fd, &k, 1);
    if (byte_code(tab[2]) == 2) {
        p = little_to_big_endian(p);
        write(fd, &p, 4);
    } else if (byte_code(tab[2]) == 3) {
        p = little_to_big_endian(p);
        b = (p >> 16) | (p << 16);
        write(fd, &b, 2);
    } else
        write(fd, &p, 1);
}

int write_xor(int fd, char **tab, asm_t *asl)
{
    char m = 0x08;
    int byte = 0;
    int args[3] = {byte_code(tab[1]), byte_code(tab[2]), byte_code(tab[3])};
    int n = my_getnbr(problem_2(tab[3], 'r'));
    int b = 0;

    for (int m = 1; tab[m]; m++)
        byte |= (args[m - 1] << (2 * (4 - m)));
    write(fd, &m, 1);
    write(fd, &byte, 1);
    write_xor_xor(fd, tab, asl, b);
    write(fd, &n, 1);
    return (0);
}