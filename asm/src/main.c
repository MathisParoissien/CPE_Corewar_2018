/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** main
*/

#include "../include/corewar.h"

int main(int ac, char **av)
{
    asm_t *asl = xmalloc(sizeof(asm_t));
    int i = 1;

    check_usage(ac, av[0]);
    init_function(asl);
    while (i < ac) {
        if ((asl->fd = check_file(av[i])) != 84) {
            get_core(asl, my_strndup(av[i], my_strlen(av[i]) - 2));
            get_body(asl);
            get_champ(asl);
            write_champ(asl);
        }
        close(asl->fd);
        i++;
    }
    free_function(asl);
    return (0);
}