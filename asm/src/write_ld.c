/*
** EPITECH PROJECT, 2019
** asm
** File description:
** write_ld
*/

#include "../include/corewar.h"

int byte_code(char *str)
{
    if (!(str))
        exit(84);
    if (str[0] == DIRECT_CHAR)
        return (T_DIR);
    else if (str[0] == 'r')
        return (T_REG);
    else
        return (T_IND - 1);
}

int write_ld(int fd, char **tab, asm_t *asl)
{
    char m = 0x02;
    int byte = 0;
    int args[2] = {byte_code(tab[1]), byte_code(tab[2])};
    int k = coffee(tab[1], asl);
    int p = my_getnbr(problem_2(tab[2], 'r'));
    int b = 0;

    for (int m = 1; tab[m]; m++)
        byte |= (args[m - 1] << (2 * (4 - m)));
    write(fd, &m, 1);
    write(fd, &byte, 1);
    if (byte_code(tab[1]) == 3) {
        k = little_to_big_endian(k);
        b = (k >> 16) | (k << 16);
        write(fd, &b, 2);
    } else {
        k = little_to_big_endian(k);
        write(fd, &k, 4);
    }
    write(fd, &p, byte_code(tab[2]));
    return (0);
}