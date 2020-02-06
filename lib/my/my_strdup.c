/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** copy a string in another whith allocate memory
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int i = 0;
    char *return_value;

    return_value = malloc (sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0')
    {
        return_value[i] = src[i];
        i = i + 1;
    }
    return_value[i] = '\0';
    return (return_value);
}
