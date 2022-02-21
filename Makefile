# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 00:44:59 by bducrocq          #+#    #+#              #
#    Updated: 2022/02/21 00:45:08 by bducrocq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 00:20:40 by bducrocq          #+#    #+#              #
#    Updated: 2022/02/10 23:05:36 by bducrocq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
HEADER = ./includes/ft_printf.h
LIBFT = -C ./libft

FILES = ft_printf \
		print_hexa 

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


all : ${NAME}

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