# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 00:44:59 by bducrocq          #+#    #+#              #
#    Updated: 2022/02/24 19:20:21 by bducrocq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
HEADER = ./includes/minitalk.h
LIBFT = -C ./libft

FILES =	utils

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


all : server.out client.out

server.out : client.out
client.out : ${NAME}
	gcc $(FLAGS) libft/libft.a server.c -o server.out
	gcc $(FLAGS) libft/libft.a client.c -o client.out

.c.o: ${SRCS} $(HEADER)
	gcc -c ${FLAGS} ${SRCS}

$(NAME) : $(OBJS)
	${MAKE} $(LIBFT)
	${MAKE} bonus $(LIBFT)
	cp libft/libft.a $(NAME)
	$(AR) $@ $^ 

clean:
	${MAKE} clean $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	${MAKE} fclean $(LIBFT)
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re