# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tadey <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 23:34:56 by tadey             #+#    #+#              #
#    Updated: 2018/01/23 16:45:12 by tadey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.c libft/*.c \
	  get_next_line.c \
	  main.c\

FLAGS = -Wall -Werror -Wextra

all:
	gcc $(FLAGS) $(SRC)
