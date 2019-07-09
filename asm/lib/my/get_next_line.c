/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** main
*/

#include "my.h"

char *add_mem(char *str)
{
    char *replace;
    int i = 0;
    int mallocsize;

    mallocsize = my_strlen(str) + 2;
    replace = malloc(sizeof(char) * mallocsize);
    if (replace == NULL)
        return (NULL);
    while (str[i] != '\0') {
        replace[i] = str[i];
        i++;
    }
    replace[i + 1] = '\0';
    return (replace);
}

char get_act_char(const int fd)
{
    static char buff[1];
    static char *ptr;
    static int ct = 0;
    char act_char;

    if (ct == 0) {
        ct = read(fd, buff, 1);
        if (ct == 0)
            return (0);
        ptr = buff;
    }
    act_char = *ptr;
    ptr = ptr + 1;
    ct = ct - 1;
    return (act_char);
}

char *get_next_line(const int fd)
{
    int i = 0;
    char act_char;
    char *str;

    if ((str = malloc(sizeof(char) * 2)) == NULL)
        return (NULL);
    str[1] = '\0';
    act_char = get_act_char(fd);
    while (act_char != '\n') {
        if (act_char == '\0')
            return (NULL);
        str[i++] = act_char;
        str = add_mem(str);
        act_char = get_act_char(fd);
        if (act_char == '\0') {
            str[i] = '\0';
            return (str);
        }
    }
    str[i] = '\0';
    return (str);
}
