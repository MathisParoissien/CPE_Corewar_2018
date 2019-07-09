/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** champ
*/

#include "../include/corewar.h"

void get_champ(asm_t *asl)
{
    if (!(asl->lines[0]) && !(asl->lines[1]))
        print_error("The file is empty\n", 1);
    if ((asl->lines[0]))
        get_name(asl);
    if ((asl->lines[1]))
        get_comment(asl);
    if ((asl->lines[2])) {
        get_labels(asl);
        if ((asl->labels))
            check_labels(asl);
        check_opcode(asl);
    }
}