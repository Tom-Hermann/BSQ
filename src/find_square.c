/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** find_square
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "file_systems.h"

void find_square(char **original, int **stock_size, int line, int nbchar)
{
    int i = 0;
    int y = 0;

    while (y != line) {
        while (i != nbchar) {
            if (stock_size[y][i] != 0 && y != 0 && i != 0)
                stock_size[y][i] = size_square(stock_size, i, y) + 1;
            else if ((y == 0 || i == 0 ) && stock_size[y][i] != 0)
                stock_size[y][i] = 1;
            i = i + 1;
        }
        y = y + 1;
        i = 0;
    }
    bigest_square(original, stock_size, line, nbchar);
}

void bigest_square(char **original, int **stock_size, int line, int nbchar)
{
    int i = 0;
    int y = 0;
    square_t data;

    data.size = 1;
    data.x = -1;
    data.y = -1;
    while (y != line) {
        while (i != nbchar) {
            if (stock_size[y][i] > data.size) {
                data.size = stock_size[y][i];
                data.x = i;
                data.y = y;
            }
            i = i + 1;
        }
        i = 0;
        y = y + 1;
    }
    draws_square(original, data);
}

void draws_square(char **original, square_t data)
{
    int i = data.x;
    int y = data.y;
    while (y > data.y - data.size) {
        while (i > data.x - data.size && i != -1) {
            original[y][i] = 'x';
            i = i - 1;
        }
        i = data.x;
        y = y - 1;
    }
    if (data.size == 1)
        original = square_one(original);
    i = 0;
    while (original[i][0] != 0 && original[i][0] != '\n') {
        my_putstr(original[i]);
        my_putchar('\n');
        i = i + 1;
    }
}

int size_square(int **stock_size, int i, int y)
{
    int up_left = stock_size[y - 1][i - 1];
    int up = stock_size[y - 1][i];
    int left = stock_size[y][i - 1];

    if (up <= left && up_left <= left)
        if (up <= up_left)
            return (up);
        else
            return (up_left);
    else if (left <= up && up_left <= up)
        if (left <= up_left)
            return (left);
        else
            return (up_left);
    else
        if (up <= left)
            return (up);
        else
            return (left);
    return (0);
}

char **square_one(char **original)
{
    int i = 0;
    int y = 0;
    while (original[y][0] != 0) {
        while (original[y][i] != 0) {
            if (original[y][i] == '.') {
                original[y][i] = 'x';
                return (original);
            }
            i = i + 1;
        }
        i = 0;
        y = y + 1;
    }
    return (original);
}