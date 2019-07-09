/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include "op.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct label_s {
    char *name;
    int prog_idx;
} label_t;

typedef struct s_asm {
    label_t **labels;
    header_t header;
    char **lines;
    char *cor;
    char *name;
    char *comment;
    int prog_size;
    int fd;
    int index_core;
    int there_is_a_lab;
} asm_t;

void print_error(char *error, bool critical);
void *xmalloc(const size_t size);
void init_function(asm_t *asl);
void free_function(asm_t *asl);
void check_usage(int ac, char *av);
int check_file(char *path);
void aff_tab(char **tab, char c);
void get_champ(asm_t *asl);
int get_name(asm_t *asl);
int my_tablen(char **tab);
int check_bla(char *str);
void get_core(asm_t *asl, char *str);
void get_body(asm_t *asl);
int get_comment(asm_t *asl);
int wima(asm_t *asl, char *str, char *mne);
int is_a_mne(char *str);
char *clear_spaces(char *buff);
char **my_str_to_word_array_cor(char const *str);
char *problem_2(char *str, char p);
int little_to_big_endian(int num);
void write_champ(asm_t *asl);
void get_labels(asm_t *asl);
void check_labels(asm_t *asl);
void check_opcode(asm_t *asl);
char **delete_f(char **tab);
char *my_strstr(char *s, char *find);
int is_octal(char *mne);
int is_label(asm_t *asl, char *babel);
int check_char(char *str);
int add_label(asm_t *asl, char *str);
void get_labels(asm_t *asl);
int label_idx(asm_t *asl, int p, int len);
void *find_label(char *str);
int same_label(asm_t *asl, char *babel);

int coffee(char *str, asm_t *asl);
int byte_code(char *str);
int write_live(int fd, char **tab, asm_t *asl);
int write_ld(int fd, char **tab, asm_t *asl);
int write_st(int fd, char **tab, asm_t *asl);
int write_add(int fd, char **tab, asm_t *asl);
int write_sub(int fd, char **tab, asm_t *asl);
int write_and(int fd, char **tab, asm_t *asl);
int write_or(int fd, char **tab, asm_t *asl);
int write_xor(int fd, char **tab, asm_t *asl);
int write_zjmp(int fd, char **tab, asm_t *asl);
int write_fork(int fd, char **tab, asm_t *asl);
int write_lfork(int fd, char **tab, asm_t *asl);
int write_aff(int fd, char **tab, asm_t *asl);
int write_ldi(int fd, char **tab, asm_t *asl);
int write_sti(int fd, char **tab, asm_t *asl);
int write_lld(int fd, char **tab, asm_t *asl);
int write_lldi(int fd, char **tab, asm_t *asl);

#define EX (my_strcmp(mne, "zjmp") == 0 || \
my_strcmp(mne, "ldi") == 0 || \
my_strcmp(mne, "sti") == 0 || \
my_strcmp(mne, "fork") == 0 || \
my_strcmp(mne, "lldi") == 0 || \
my_strcmp(mne, "lfork") == 0)

#define EXEPTION (my_strcmp(op_tab[i].mnemonique, "zjmp") == 0 || \
my_strcmp(op_tab[i].mnemonique, "ldi") == 0 || \
my_strcmp(op_tab[i].mnemonique, "sti") == 0 || \
my_strcmp(op_tab[i].mnemonique, "fork") == 0 || \
my_strcmp(op_tab[i].mnemonique, "lldi") == 0 || \
my_strcmp(op_tab[i].mnemonique, "lfork") == 0)

#define MNEUMONIQUE (my_strcmp(op_tab[i].mnemonique, "live") == 0 || \
my_strcmp(op_tab[i].mnemonique, "zjmp") == 0 || \
my_strcmp(op_tab[i].mnemonique, "fork") == 0 || \
my_strcmp(op_tab[i].mnemonique, "lfork") == 0)

#define POINTEUR "live", "ld", "st", "add", "sub", "and", "or", "xor", \
"zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff", NULL

#define INIT char *flags[17] = {POINTEUR}; \
int (*fls[16])(int, char **, asm_t *); int i = -1;

#define NORME int d = 0;

#define hihi k = 0; d = 0;

#define haha k++; d++;

#define OCTAL {"ld", "st", "add", "sub", "and", "or", "xor", "ldi", "sti", \
"lld", "lldi", "aff"}

#define ELSE else

#endif /* !COREWAR_H_ */