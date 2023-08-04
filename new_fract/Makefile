# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 11:48:03 by evportel          #+#    #+#              #
#    Updated: 2023/08/04 15:29:03 by evportel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR ********************************************************************** #
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
MAGENTA	=	\033[35m
CYAN	=	\033[36m
RESET	=	\033[0m

# VAR ************************************************************************ #
NAME	=	fractol
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
MLX		=	-lmlx -lX11 -lXext -lm -lz
# MLX		=	-Lmlx -Lmlx_linux -Imlx-linux

SRC		=	${addprefix sources/mandelbrot/, mandelbrot.c}\
			${addprefix sources/julia/, julia.c}\
			${addprefix sources/, main.c}
OBJ		=	${SRC:.c=.o}
HEADER	=	include/fractol.h

# RULES ********************************************************************** #
all:		${NAME}


${NAME}:	${OBJ}
	@printf "${BLUE}All objects created!${RESET}\n"
	@cc ${FLAGS} -Iinclude ${OBJ} -o $@ ${MLX}
	@printf "${GREEN}${NAME} created!${RESET}\n"
	@exit 0


%.o: %.c
	@printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
	@cc ${FLAGS} -Iinclude -c $< -o $@


clean:
	@rm -fr ${OBJ}
	@printf "${YELLOW}Objects removed!${RESET}\n"


fclean:		clean
	@rm -fr ${NAME}
	@printf "${RED}${NAME} removed!${RESET}\n"

re:			fclean ${NAME}


.PHONY: all clean fclean re