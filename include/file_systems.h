/*
** EPITECH PROJECT, 2019
** header of file system
** File description:
** header file
*/

#ifndef FILE_SYS_H_
#define FILE_SYS_H_

typedef struct s_square
{
    int size;
    int x;
    int y;

}square_t;

int bsq(char *file);
void put_in_char_double(int line, int nbchar, int file);
void put_char_nb(char *original, int line, int nbchar);
void init_nb(char **original, int line, int nbchar);
void find_square(char **original, int **stock_size, int line, int nbchar);
char **anti_chiant(char **s);
int size_square(int **stock_size, int i, int y);
void bigest_square(char **original, int **stock_size, int line, int nbchar);
void draws_square(char **original, square_t data);
char **square_one(char **original);
int **firstline(char **original, int **stock_size, int nbchar);
int error(int argc, char **argv);


#endif /* !FILE_SYS_H_ */