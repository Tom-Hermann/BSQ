/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    char temp = ' ';
    int end = my_strlen(str) - 1;

    if (my_strlen(str) == 1) {
        return (str);
    }
    while (i <= end / 2)
    {
        temp = str [i];
        str [i] = str [end - i];
        str [end - i] = temp;
        i = i + 1;
    }
    return (str);
}