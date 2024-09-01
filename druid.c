/*
** EPITECH PROJECT, 2023
** druid
** File description:
** druid
*/

#include "my.h"

void druid_refile(global_t *global)
{
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I "
    "can only make %d more refills after this one."
    "\n", global->druid->nb_refills - 1);
    global->druid->nb_refills--;
    global->druid->nb_potions = global->druid->pot_size;
}

void *thread_func_druid_start(void *arg)
{
    global_t *global = (global_t *) arg;
    printf("Druid: I'm ready... but sleepy...\n");
    while (global->druid->nb_refills > 0 && villager_open(global)) {
        int is_cum = -1;
        sem_getvalue(&global->semaphore, &is_cum);
        // printf("%d\n", is_cum);
        if (is_cum == 0) {
            druid_refile(global);
            // sleep(1);
        }
    }
    if (global->druid->nb_refills <= 0)
        printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return (NULL);
}
