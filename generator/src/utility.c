/*
** EPITECH PROJECT, 2019
** dante_star
** File description:
** dante_star
*/

#include "../include/dante_star.h"

int random_number(int min_num, int max_num)
{
    int result = 0;
    int low_num = 0;
    int hi_num = 0;

    if (min_num < max_num) {
        low_num = min_num;
        hi_num = max_num + 1;
    } else {
        low_num = max_num + 1;
        hi_num = min_num;
    }
    result = rand();
    srand(result);
    result = result  % (hi_num - low_num) + low_num;
    return (result);
}

char *init_map(int x, int y)
{
    int size = (x + 1) * y;
    char *map = malloc(sizeof(char) * (size + 1));

    for (int i = 1; i < size; i++) {
        if (i % (x + 1) == 0)
             map[i - 1] = '\n';
        else
            map[i - 1] = '#';
    }
    map[size] = '\0';
    return (map);
}

int *init_tab(int x, int y)
{
    int size = (x * y) / 4;
    int *tab = malloc(sizeof(int) * (size + 1));

    tab[0] = 0;
    return (tab);
}

void init_data_around(data_around_t *data_around)
{
    data_around->left = 0;
    data_around->count = 0;
    data_around->down = 0;
    data_around->right = 0;
    data_around->up = 0;
}