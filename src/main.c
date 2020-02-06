/*
** EPITECH PROJECT, 2019
** 102architect_2019
** File description:
** main
*/

#include "my.h"
#include "file_systems.h"

int main(int argc, char **argv)
{
    if (error(argc, argv) == 84)
        return (84);
    bsq(argv[1]);
    return (0);
}
