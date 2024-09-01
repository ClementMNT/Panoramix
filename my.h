/*
** EPITECH PROJECT, 2023
** include
** File description:
** my
*/

#pragma once

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct druid_s {
    int pot_size;
    int nb_potions;
    int nb_refills;
} druid_t;

typedef struct villager_s {
    int nb_villagers;
    int nb_fights;
    int thread_id;
    int *fight_left;
} villager_t;

typedef struct global_s {
    druid_t *druid;
    villager_t *villager;
    pthread_mutex_t mutex;
    sem_t semaphore;
} global_t;

int panoramix(global_t global);
int check_arg(char **av, global_t *global);
int my_str_isnum(char *str);
int druid_popo(global_t *global);
int villager_open(global_t *global);
global_t *init_global(global_t *global, char **av);
void *thread_func_druid_start(void *arg);
void *thread_func_villagers(void *arg);
