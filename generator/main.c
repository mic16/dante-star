/*
** EPITECH PROJECT, 2019
** dante_star
** File description:
** dante_star
*/

#include "include/dante_star.h"

void nb_open_around(char *tab, int ind, data_t *data, data_around_t *d_a)
{
    if (ind - 2 >= 0 && tab[ind - 1] != '\n' && \
    tab[ind - 2] != '\n' && tab[ind - 2] == '#') {
        d_a->left = 1;
        d_a->index_left = d_a->count++;
    }
    if (ind + 2 < data->x_y_1 && tab[ind + 1] != '\n' && \
    tab[ind + 2] != '\n' && tab[ind + 2] != '\0' && tab[ind + 2] == '#') {
        d_a->right = 1;
        d_a->index_right = d_a->count++;
    }
    if (ind + data->x_2 + 2 < data->x_y_1 && \
    tab[ind + data->x_2 + 2] == '#') {
        d_a->down = 1;
        d_a->index_down = d_a->count++;
    }
    if (ind - data->x_2 - 2 >= 0 && tab[ind - data->x_2 - 2] == '#') {
        d_a->up = 1;
        d_a->index_up = d_a->count++;
    }
}

void add_case(data_around_t data_around, char *tab, int *tab_int, data_t *data)
{
    int random = random_number(0, data_around.count);

    if (data_around.left == 1 && data_around.index_left == random) {
        tab[tab_int[data->nb_elem - 1] - 2] = '*'; 
        tab[tab_int[data->nb_elem++ - 1] - 1] = '*'; 
        tab_int[data->nb_elem - 1] = tab_int[data->nb_elem - 2] - 2;
    } else if (data_around.right == 1 && data_around.index_right == random) {
        tab[tab_int[data->nb_elem - 1] + 2] = '*'; 
        tab[tab_int[data->nb_elem++ - 1] + 1] = '*'; 
        tab_int[data->nb_elem - 1] = tab_int[data->nb_elem - 2] + 2;
    } 
    if (data_around.down == 1 && data_around.index_down == random) {
        tab[tab_int[data->nb_elem - 1] + data->x_2 + 2] = '*'; 
        tab[tab_int[data->nb_elem++ - 1] + data->x + 1] = '*'; 
        tab_int[data->nb_elem - 1] = tab_int[data->nb_elem - 2] + data->x_2 + 2;
    } else if(data_around.up == 1 && data_around.index_up == random) {
        tab[tab_int[data->nb_elem - 1] - data->x_2 - 2] = '*'; 
        tab[tab_int[data->nb_elem++ - 1] - data->x - 1] = '*'; 
        tab_int[data->nb_elem - 1] = tab_int[data->nb_elem - 2] - data->x_2 - 2;
    }
}

void create_maze(char *tab, int x, int y)
{
    int *tab_int = init_tab(x, y);
    int i = 0;
    data_around_t data_around;
    data_t data;

    data.x_2 = 2 * x;
    data.x = x;
    data.y = y;
    data.nb_elem = 1;
    data.x_y_1 = (x + 1) * y;
    tab[i] = '*';
    while (data.nb_elem > 0) {
        init_data_around(&data_around);
        nb_open_around(tab, tab_int[data.nb_elem - 1], &data, &data_around);
        if (data_around.count == 0) {
            data.nb_elem -= 1;
            continue;
        }
        add_case(data_around, tab, tab_int, &data);
    }
}

int main(int ac, char **av)
{
    int x = 0;
    int y = 0;
    char *tab = NULL;

    if (ac < 3)
        return (0);
    x = atoi(av[1]);
    y = atoi(av[2]);
    tab = init_map(x, y);
    srand(time(NULL));
    create_maze(tab, x, y);  
    printf("%s", tab);
    return (0);
}