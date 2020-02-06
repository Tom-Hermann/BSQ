/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** error
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int error_on_file(int file)
{
    char buffer[2] = "0\0";
    read(file, buffer, 1);
    while (buffer[0] != '\n') {
        if (buffer[0] < '0' || buffer[0] > '9') {
            write(2, "Error first line (need number of line)\n", 39);
            return (84);
        }
        read(file, buffer, 1);
    }
    while (read(file, buffer, 1) != 0) {
        if (buffer[0] != 'o' && buffer[0] != '.' && buffer[0] != '\n') {
            write(2, "Error on file\n", 14);
            return (84);
        }
    }
    return (0);
}

int error(int argc, char **argv)
{
    int file = open(argv[1], O_RDONLY);

    if (argc != 2) {
        write(2, "Error arguments.\n", 17);
        return (84);
    }
    if (file <= 0) {
        write(2, "No file has this name.\n", 23);
        return (84);
    }
    if (error_on_file(file) == 84)
        return (84);
    return (0);
}