#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{

// int status = system("gcc *.c -fsanitize=address -g3 libft/libft.a && ./a.out");  //gfs
int status = system("gcc ./libft/ft_putstr_fd.o ./libft/ft_calloc.o ./libft/ft_bzero.o ./libft/ft_memset.o  utils.c client.c -o client");                   //gf
// int status = system("gcc ./libft/ft_putstr_fd.o ./libft/ft_calloc.o ./libft/ft_bzero.o ./libft/ft_memset.o  client.c -o client");                   //gf
// int status = system("gcc ../libft/ft_putstr_fd.o ../libft/ft_calloc.o ../libft/ft_bzero.o ../libft/ft_memset.o  ../server.c -o ../server");                   //gf
//int status = system("gcc libft/ft_putstr_fd.o libft/ft_calloc.o libft/ft_bzero.o libft/ft_memset.o  client.c -o client");                   //gf
// int status = system("gcc *.c libftprintf.a && ./a.out");
}