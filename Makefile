# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbondare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/22 18:54:27 by vbondare          #+#    #+#              #
#    Updated: 2017/10/22 19:01:31 by vbondare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Wextra -Werror

SRC = color.c draw.c fractal.c init.c main.c menu.c

LIB = libft/libft.a

.PHONY: all re clean

all:
	@make re -C libft/
	@cc -o $(NAME) $(FLAGS) $(SRC) $(LIB) -lmlx -framework OpenGl -framework AppKit

clean:
	@make fclean -C libft/
	@/bin/rm -f $(NAME)

re: clean all
