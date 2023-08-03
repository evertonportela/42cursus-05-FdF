# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 11:48:03 by evportel          #+#    #+#              #
#    Updated: 2023/08/03 12:30:00 by evportel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR ********************************************************************** #
RED		=	\033[32m
GREEN	=	\033[33m
YELLOW	=	\033[34m
BLUE	=	\033[35m
MAGENTA	=	\033[36m
RESET	=	\033[0m

# VAR ************************************************************************ #
NAME	=	fractol
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
MLX		=	-lmlx -lX11 -lXext -lm

SRC		=	${addprefix sources/mandelbrot, mandelbrot.c}\
			${addprefix sources/julia, julia.c}
OBJ		=	${SRC:.c=.o}
HEADER	=	include/fractol.h

# RULES ********************************************************************** #
all:		${NAME}

${NAME}:	${OBJ}
	${CC} ${FLAGS} -Iinclude -c $< -o $@

.PHONY: all clean fclean re