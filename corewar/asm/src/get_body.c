/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** get_body
*/

#include "../include/corewar.h"

void aff_tab(char **tab, char c)
{
    int i = 0;

    while ((tab[i])) {
        my_putstr(tab[i]);
        my_putchar(c);
        i++;
    }
}

char *clear_spaces(char *buff)
{
    char *res = xmalloc(sizeof(char) * my_strlen(buff) + 1);
    int i = -1;
    int k = -1;

    while ((buff[++i])) {
        if (buff[i] == ' ' && buff[i + 1] == ' ') {
            res[++k] = ' ';
            i += 2;
        } else
            res[++k] = buff[i];
    }
    res[k + 1] = '\0';
    return (res);
}

char *clear_line(char *str)
{
    char *buff = xmalloc(sizeof(char) * my_strlen(str) + 1);
    int i = -1;
    int k = -1;

    while ((str[++i])) {
        if (str[i] == '\t' || str[i] == '\n')
            buff[++k] = ' ';
        else
            buff[++k] = str[i];
    }
    buff[k + 1] = '\0';
    return (buff);
}

void get_body(asm_t *asl)
{
    char *line = NULL;
    int i = 0;
    char cm[2];

    cm[0] = COMMENT_CHAR;
    cm[1] = '\0';
    asl->lines = xmalloc(sizeof(char *) * 100000);
    while ((line = get_next_line(asl->fd))) {
        if (line[0] != COMMENT_CHAR) {
            asl->lines[i] = clear_line(line);
            if (my_strstr(asl->lines[i], cm))
                *my_strstr(asl->lines[i], cm) = 0;
            i++;
        }
        free(line);
    }
    asl->lines[i] = NULL;
}