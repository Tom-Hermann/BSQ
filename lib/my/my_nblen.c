/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_nblen
*/

int my_nblen(unsigned int nb)
{
    unsigned int i = 10;
    int y = 1;

    while (nb / i != 0) {
        i = i * 10;
        y = y + 1;
    }
    return (y);
}