/*
** EPITECH PROJECT, 2023
** usefull
** File description:
** fonction
*/

#include "my.h"

int check_arg(char **av, global_t *global)
{
    for (int i = 1; av[i]; i++) {
        if (my_str_isnum(av[i]) == 0)
            return (84);
        if (atoi(av[i]) <= 0)
            return (84);
    }
    global = init_global(global, av);
    return (0);
}

int my_str_isnum(char *str)
{
    if (str[0] == '-')
        str++;
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}

int druid_popo(global_t *global)
{
    if (global->druid->nb_refills <= 0 && global->druid->nb_potions <= 0) {
        return (0);
    }
    return (1);
}

int villager_open(global_t *global)
{
    for (int i = 0; i < global->villager->nb_villagers; i++) {
        if (global->villager->fight_left[i] > 0)
            return (1);
    }
    return (0);
}
