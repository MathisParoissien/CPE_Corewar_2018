/*
** EPITECH PROJECT, 2019
** asm
** File description:
** write
*/

#include "../include/corewar.h"

int little_to_big_endian(int num)
{
    int s = 0x00;

    s = ((num >> 24) & 0xff) | ((num << 8) & 0xff0000) | \
    ((num >> 8) & 0xff00) | ((num << 24) & 0xff000000);
    return (s);
}

int pointeur_sur_fonction(int fd, char **tab, asm_t *asl)
{
    INIT

    fls[0] = &write_live;
    fls[1] = &write_ld;
    fls[2] = &write_st;
    fls[3] = &write_add;
    fls[4] = &write_sub;
    fls[5] = &write_and;
    fls[6] = &write_or;
    fls[7] = &write_xor;
    fls[8] = &write_zjmp;
    fls[9] = &write_ldi;
    fls[10] = &write_sti;
    fls[11] = &write_fork;
    fls[12] = &write_lld;
    fls[13] = &write_lldi;
    fls[14] = &write_lfork;
    fls[15] = &write_aff;

    while ((flags[++i]) && i <= 16 && my_strcmp(flags[i], tab[0]) != 0);
    return (fls[i](fd, tab, asl));
}

void write_op(asm_t *asl, int fd)
{
    int i = 2;
    char **tab = NULL;

    asl->index_core = 3;
    while (asl->lines[++i]) {
        tab = my_str_to_word_array_cor(asl->lines[i]);
        if (tab[0] && tab[0][my_strlen(tab[0]) - 1] == LABEL_CHAR)
            tab = delete_f(tab);
        if (tab[0] && tab[0][0] != '\0')
            pointeur_sur_fonction(fd, tab, asl);
        asl->index_core++;
    }
}

void write_champ(asm_t *asl)
{
    int fd = 0;
    header_t *header = xmalloc(sizeof(header_t));

    my_strcat(asl->cor, ".cor");
    if ((fd = open(asl->cor, O_CREAT | O_RDWR | O_TRUNC, 0644)) == -1)
        print_error("problemo create file\n", 1);
    header->magic = 0;
    header->magic = little_to_big_endian(COREWAR_EXEC_MAGIC);
    header->prog_size = asl->prog_size;
    header->prog_size = little_to_big_endian(header->prog_size);
    my_strcpy(header->prog_name, asl->name);
    my_strcpy(header->comment, asl->comment);
    write(fd, header, sizeof(header_t));
    write_op(asl, fd);
    close(fd);
}