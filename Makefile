# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 15:55:02 by jeluiz4           #+#    #+#              #
#    Updated: 2022/11/21 14:40:42 by jeluiz4          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = julia.c
CC = cc
FLAGS = -Wall -Wextra
NAME = fractol
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Ofast -lm -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -Imlx -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all

