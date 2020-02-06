/*
** EPITECH PROJECT, 2019
** 102architect_2019
** File description:
** BSQ
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "my.h"
#include "file_systems.h"


int **malloc_nb(int line, int nb_char)
{
    int i = 0;
    int **stock_size = malloc(sizeof(int *) * line);

    while (i != line) {
        stock_size[i] = malloc(sizeof(int) * (nb_char));
        i = i + 1;
    }
    return (stock_size);
}

int bsq(char *file)
{
    int file_op = open(file, O_RDONLY);
    int line = 0;
    int i = 0;
    char tamp[2] = "0\0";
    struct stat filestat;

    stat(file, &filestat);
    while (tamp[0] <= '9' && tamp[0] >= '0') {
        line = line + tamp[0] - 48;
        line = line * 10;
        i = i + 1;
        read(file_op, tamp, 1);
    }
    line = line / 10;
    if (line == 1)
        filestat.st_size = filestat.st_size - 2;
    put_in_char_double(line, filestat.st_size / line, file_op);
    close(file_op);
    return (0);
}

void put_in_char_double(int line, int nbchar, int file)
{
    char **original = malloc(sizeof(char *) * (line + 1));
    char *tampo = malloc(sizeof(char) * nbchar);
    int i = 0;
    int y = 0;

    while (i <= line) {
        original[i] = malloc(sizeof(char) * nbchar);
        i = i + 1;
    }
    while (y != line) {
        read(file, tampo, nbchar);
        tampo[nbchar - 1] = 0;
        original[y] = my_strdup(tampo);
        original[y][nbchar - 1] = 0;
        y = y + 1;
    }
    original[y][0] = 0;
    init_nb(original, line, nbchar);
}

void init_nb(char **original, int line, int nbchar)
{
    int i = 0;
    int y = 0;
    int **stock_size = malloc_nb(line, nbchar);
    while (y != line) {
        i = 0;
        if (original[y][0] == '.')
            stock_size[y][0] = 1;
        while (i != nbchar - 1) {
            if (original[y][i] == 'o')
                stock_size[y][i] = 0;
            else
                stock_size[y][i] = 1;
            i = i + 1;
        }
        y = y + 1;
    }
    find_square(original, stock_size, line, nbchar);
}

int **firstline(char **original, int **stock_size, int nbchar)
{
    int i = 0;
    while (i != nbchar) {
        if (original[0][i] == '.')
            stock_size[0][i] = 1;
        i = i + 1;
    }
    return (stock_size);
}