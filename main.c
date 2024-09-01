/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "my.h"

int panoramix(global_t global)
{
    villager_t *villager = global.villager;
    pthread_t *villagers = malloc(sizeof(pthread_t) * villager->nb_villagers);
    pthread_t druid_thread;
    pthread_create(&druid_thread, NULL, thread_func_druid_start, &global);
    for (int i = 0; i < villager->nb_villagers; i++) {
        pthread_create(&villagers[i], NULL, thread_func_villagers, &global);
    }
    for (int i = 0; i < villager->nb_villagers; i++) {
        pthread_join(villagers[i], NULL);
    }
    pthread_join(druid_thread, NULL);
    pthread_mutex_destroy(&global.mutex);
    return (0);
}

global_t *init_global(global_t *global, char **av)
{
    druid_t *druid = malloc(sizeof(druid_t));
    villager_t *villager = malloc(sizeof(villager_t));
    villager->nb_villagers = atoi(av[1]);
    druid->pot_size = atoi(av[2]);
    druid->nb_potions = atoi(av[2]);
    villager->nb_fights = atoi(av[3]);
    druid->nb_refills = atoi(av[4]);
    villager->fight_left = malloc(sizeof(int) * villager->nb_villagers);
    villager->thread_id = -1;
    for (int i = 0; i < villager->nb_villagers; i++)
        villager->fight_left[i] = villager->nb_fights;
    global->druid = druid;
    global->villager = villager;
    pthread_mutex_init(&global->mutex, NULL);
    sem_init(&global->semaphore, 0, 1);
    return (global);
}

int main(int ac, char **av)
{
    if (ac != 5)
        return (84);
    global_t global;
    if (check_arg(av, &global) == 84)
        return (84);
    return (panoramix(global));
}
