# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 11:48:03 by evportel          #+#    #+#              #
#    Updated: 2023/08/16 11:43:59 by evportel         ###   ########.fr        #
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
# MLX		=	-lmlx -framework OpenGL -framework AppKit 


SRC		=	${addprefix sources/mandelbrot/, fct_mandelbrot.c}\
			${addprefix sources/julia/, fct_julia.c}\
			${addprefix sources/utils/, fct_color.c}\
			${addprefix sources/utils/, fct_draw.c}\
			${addprefix sources/utils/, ft_strncmp.c}\
			${addprefix sources/utils/, utils_char_to_double.c}\
			${addprefix sources/utils/, utils_check_args.c}\
			${addprefix sources/utils/, utils_check_double.c}\
			${addprefix sources/utils/, utils_close_window.c}\
			${addprefix sources/utils/, utils_key_input.c}\
			${addprefix sources/utils/, utils_fractol_zoom.c}\
			${addprefix sources/utils/, utils_struct_init.c}\
			${addprefix sources/utils/, utils_update_iterator.c}\
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

devm:
	clear
	@make re
	./fractol Mandelbrot

devj:
	clear
	@make re
	./fractol Julia -0.08 0.724

.PHONY: all clean fclean re