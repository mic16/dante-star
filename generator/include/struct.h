/*
** EPITECH PROJECT, 2019
** dante_star
** File description:
** dante_star
*/

#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct data_around_s{
    int left;
    int index_left;
    int right;
    int index_right;
    int up;
    int index_up;
    int down;
    int index_down;
    int count;
} data_around_t;

typedef struct data_s {
    int y;
    int x;
    int x_2;
    int nb_elem;
    int x_y_1;
} data_t;