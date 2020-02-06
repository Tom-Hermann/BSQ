/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

int my_compute_power_rec(int nb, int p)
{
    int i = 1;
    int save = nb;
    if (p == 0)
        return (1);
    else if (p < 0)
        return (0);

    while (i != p)
    {
        i = i + 1;
        nb = nb * save;
    }
    return (nb);
}
