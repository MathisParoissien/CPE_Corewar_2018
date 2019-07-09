/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include "op.h"
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

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define BLANK "\033[0m"

#define LIVE 1
#define LD 2
#define ST 3
#define ADD 4
#define SUB 5
#define AND 6
#define OR 7
#define XOR 8
#define ZJMP 9
#define LDI 10
#define STI 11
#define FORK 12
#define LLD 13
#define LLDI 14
#define LFORK 15

typedef struct s_instance
{
    char *Name;
    char *Comment;
    short InstanceIndex;
    int InstanceNumber;
    int Parent;
    int LastLive;
    int LiveCount;
    int Delay;
    int CurrentCycle;
    char Carry;
    int PC;
    int Args[16];
    struct s_instance *next;
} t_instance;

typedef struct s_vm
{
    t_instance *champs;
    int CycleToDie;
    int CycleMax;
    int CycleForTurn;
    int LiveCount;
    int InstanceCount;
    char InstanceNameForLastAction[80];
    unsigned char CurrentAction;
    int Index;
    char *MemoryMap;
} t_vm;

#endif /* !COREWAR_H_ */
