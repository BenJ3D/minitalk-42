# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 00:44:59 by bducrocq          #+#    #+#              #
#    Updated: 2022/03/02 19:44:56 by bducrocq         ###   ########.fr        #
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

m = "gisave"

all : server client
	@chmod 700 server client

server : server.c
	gcc $(FLAGS) $(SRCS) libft/libft.a server.c -o server

client : ${NAME} client.c
	gcc $(FLAGS) $(SRCS) libft/libft.a client.c -o client

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
	$(RM) $(NAME) server server.out client client.out

re: clean all

git:
	git add .
	git commit -m "$m"
	git push

.PHONY: all clean fclean re