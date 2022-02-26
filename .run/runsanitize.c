#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
int status = system("gcc ./libft/ft_putstr_fd.o ./libft/ft_calloc.o ./libft/ft_bzero.o ./libft/ft_memset.o  utils.c server.c -o server");                   //gf
// int status = system("gcc *.c libft/libft.a && ./a.out");                   //gf
// int status = system("gcc *.c libftprintf.a && ./a.out");
}