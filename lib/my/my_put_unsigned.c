/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_unsigned
*/

int my_putchar (char c);

int my_put_unsigned (unsigned int nb)
{
    unsigned int n = 1;
    if (nb == 0) {
        my_putchar (48);
        return (0);
    }
    if (nb < 1000000000) {
        while (nb / n != 0) {
            n = n * 10;
        }
        n = n / 10;
    }
    else
        n = 1000000000;
    while (n != 0) {
        my_putchar (nb / n + 48);
        nb = nb % n;
        n = n / 10;
    }
    return (0);
}