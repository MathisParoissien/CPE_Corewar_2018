/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** main
*/

#include "../include/corewar.h"

void PrintError(char *message, bool isCritical)
{
    if (isCritical)
        my_putstr(RED);
    else
        my_putstr(YELLOW);
    my_putstr(message);
    my_putstr(BLANK "\n");
    if (isCritical)
        exit(84);
}

void *xmalloc(const size_t size)
{
    void *p;

    p = malloc(size);
    if (p == NULL)
        PrintError("A critical error occurred during memory allocation", 1);
    return (p);
}

t_vm setup_VM(char **av)
{
    t_instance *firstInstance;
    t_vm *vm;

    vm = xmalloc(sizeof(t_vm));
    vm->MemoryMap = xmalloc(sizeof(MEM_SIZE));
    
}

int main(int ac, char **av)
{
    setup_VM(av);
    return (0);
}