/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** check_file
*/

#include "../include/corewar.h"

void check_usage(int ac, char *av)
{
    if (ac == 1) {
        my_putstr("Usage ");
        my_putstr(av);
        my_putstr(" file_name[.s] ....\n");
        exit(84);
    }
}

int check_file(char *path)
{
    int fd = 0;

    if ((fd = open(path, O_RDONLY)) == -1)
        return (-1);
    else
        return (fd);
}

void get_core(asm_t *asl, char *str)
{
    int i = -1;
    int k = -1;
    int p = 0;

    while (str[++i]) {
        if (str[i] == '/')
            p++;
    } if (p > 0) {
        while (str[--i] != '/' && i > 0);
        i++;
        while (str[i]) {
            asl->cor[++k] = str[i];
            i++;
        }
        asl->cor[k + 1] = '\0';
    } else
        asl->cor = my_strdup(str);
}