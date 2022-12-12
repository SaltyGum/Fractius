# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 15:55:02 by jeluiz4           #+#    #+#              #
#    Updated: 2022/12/12 16:13:43 by jeluiz4          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	utils.c \
		triggers.c \
		parse_input.c \
		keys.c \
		lib_use.c \
		plus.c \
		menu.c

CC = gcc
FLAGS = -Wall -Wextra
NAME = fractol
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -I/usr/include -lmlx_Linux -O3 -c

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY:
	
