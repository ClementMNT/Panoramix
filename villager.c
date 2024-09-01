/*
** EPITECH PROJECT, 2023
** villager
** File description:
** villager
*/

#include "my.h"

void villager_drink(global_t *global, int thread_num)
{
    pthread_mutex_lock(&global->mutex);
    printf("Villager %d: I need a drink... I see %d "
    "servings left.\n", thread_num, global->druid->nb_potions);
    if (global->druid->nb_potions <= 0) {
        sem_wait(&global->semaphore);
        printf("Villager %d: Hey Pano wake up! "
        "We need more potion.\n", thread_num);
        while (global->druid->nb_potions < 1);
        sem_post(&global->semaphore);
    }
    global->druid->nb_potions--;
    pthread_mutex_unlock(&global->mutex);
    global->villager->fight_left[thread_num]--;
    printf("Villager %d: Take that roman scum!"
    " Only %d"
    " left.\n", thread_num, global->villager->fight_left[thread_num]);
}

void *thread_func_villagers(void *arg)
{
    global_t *global = (global_t *) arg;
    int thread_num = ++global->villager->thread_id;
    printf("Villager %d: Going into battle!\n", thread_num);
    while (global->villager->fight_left[thread_num] > 0 && druid_popo(global)) {
        villager_drink(global, thread_num);
    }
    if (global->villager->fight_left[thread_num] <= 0)
        printf("Villager %d: I'm going to sleep now.\n", thread_num);
    return (NULL);
}