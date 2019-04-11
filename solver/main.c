/*
** EPITECH PROJECT, 2019
** dante_star
** File description:
** dante_star
*/

#include "include/dante_star.h"

int is_possible(point_t finish, int y, int x)
{
    if (x < 0 || y < 0 || x > finish.x || y > finish.y)
        return (0);
    return (1);
}

char **result(point_t current, char **map, point_t finish)
{
    char **stock;

    map[current.y][current.x] = 'o';
    if (current.x == finish.x && current.y == finish.y)
        return (map);

    if (is_possible(finish, current.y, current.x + 1) && map[current.y][current.x + 1] == '*') {
        stock = result((point_t){current.x + 1, current.y}, map, finish);
        if (stock != NULL)
            return (stock);
    }
    if (is_possible(finish, current.y + 1, current.x) && map[current.y + 1][current.x] == '*') {
        stock = result((point_t){current.x, current.y + 1}, map, finish);
        if (stock != NULL)
            return (stock);
    }
    if (is_possible(finish, current.y, current.x - 1) && map[current.y][current.x - 1] == '*') {
        stock = result((point_t){current.x - 1, current.y}, map, finish);
        if (stock != NULL)
        return (stock);
    }
    if (is_possible(finish, current.y - 1, current.x) && map[current.y - 1][current.x] == '*') {
        stock = result((point_t){current.x, current.y - 1}, map, finish);
        if (stock != NULL)
            return (stock);
    }
    map[current.y][current.x] = '*';
    return (NULL);
}

void cpy_string_into_map(char **buff, char *line, FILE *fp, size_t len)
{
    ssize_t read;

    len = 0;
    for (int i = 0;(read = getline(&line, &len, fp)) != -1; i += 1) {
        buff[i] = malloc(sizeof(char) * read + 1);
        strcpy(buff[i], line);
        buff[i][read] = '\0';
    }
}

char **read_file(char *av)
{
    FILE *fp;
    char *line;
    size_t len = 0;
    char **buff;
    int mal = 0;

    fp = fopen(av, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    for (mal = 0; (getline(&line, &len, fp)) != -1; mal += 1);
    buff = malloc(sizeof(char *) * (mal + 1));
    free(line);
    fp = fopen(av, "r");
    cpy_string_into_map(buff, line, fp, len);
    if (line)
        free(line);
    buff[mal] = NULL;
    return (buff);
}

int main(int ac, char **av)
{
    char **map = NULL;
    point_t size;

    map = read_file(av[1]);
    for (size.y = 0; map[size.y] != NULL; size.y++);
    for (size.x = 0; map[0][size.x] != '\n'; size.x++);

    map = result((point_t){0, 0}, map, (point_t){size.x - 1, size.y - 1});
    for (int i = 0; map[i] != NULL; i++) {
        printf("%s",map[i]);
    }
    return (0);
}
