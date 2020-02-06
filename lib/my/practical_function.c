/*
** EPITECH PROJECT, 2019
** infin_add
** File description:
** add for bistro project
*/

#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
#include "my.h"

int p_car(int digit)
{
    int carried_nbr = digit;

    if (digit > 9)
        carried_nbr = digit - 10;
    return (carried_nbr);
}

int carried(int digit)
{
    int carried_rest = 0;

    if (digit > 9)
        carried_rest = 1;
    return (carried_rest);
}

int c_to_d(char charac)
{
    int digit = charac - '0';
    return (digit);
}

char d_to_c(int digit)
{
    char charac = digit + '0';
    return (charac);
}

char *clean_zero(char *str)
{
    int i = my_strlen(str) - 1;

    if (str[0] == '0' && str[1] == '\0')
        return ("0");
    while (str[i] == '0') {
        str[i] = '\0';
        i = i - 1;
    }
    return (str);
}