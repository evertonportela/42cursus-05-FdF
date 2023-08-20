# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 11:48:03 by evportel          #+#    #+#              #
#    Updated: 2023/08/20 11:58:05 by evportel         ###   ########.fr        #
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

# FLAGS MANDATORY ************************************************************ #
NAME	=	fractol
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
MLX		=	-lmlx -lX11 -lXext -lm -lz


SRC		=	${addprefix mandatory/sources/mandelbrot/, fct_mandelbrot.c}\
			${addprefix mandatory/sources/julia/, fct_julia.c}\
			${addprefix mandatory/sources/utils/, fct_color.c}\
			${addprefix mandatory/sources/utils/, fct_draw.c}\
			${addprefix mandatory/sources/utils/, ft_strncmp.c}\
			${addprefix mandatory/sources/utils/, utils_char_to_double.c}\
			${addprefix mandatory/sources/utils/, utils_check_args.c}\
			${addprefix mandatory/sources/utils/, utils_check_double.c}\
			${addprefix mandatory/sources/utils/, utils_close_window.c}\
			${addprefix mandatory/sources/utils/, utils_key_input.c}\
			${addprefix mandatory/sources/utils/, utils_fractol_zoom.c}\
			${addprefix mandatory/sources/utils/, utils_struct_init.c}\
			${addprefix mandatory/sources/utils/, utils_update_iterator.c}\
			${addprefix mandatory/sources/, main.c}

OBJ		=	${SRC:.c=.o}
HEADER	=	/mandatory/include/fractol.h

# FLAGS MANDATORY ************************************************************ #
NAME_BONUS		=	fractol_bonus

SRC_BONUS		=	${addprefix bonus/sources/mandelbrot/, fct_mandelbrot_bonus.c}\
					${addprefix bonus/sources/julia/, fct_julia_bonus.c}\
					${addprefix bonus/sources/, main.c}

OBJ_BONUS		=	${SRC_BONUS:.c=.o}
HEADER_BONUS	=	/bonus/include/fractol_bonus.h

# RULES MANDATORY ************************************************************ #
all:		${NAME}

${NAME}:	${OBJ}
	@printf "${BLUE}All objects created!${RESET}\n"
	@cc ${FLAGS} -Iinclude ${OBJ} -o $@ ${MLX}
	@printf "${GREEN}${NAME} created!${RESET}\n"
	@exit 0

%.o: %.c
	@printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
	@cc ${FLAGS} -Iinclude -c $< -o $@

# RULES BONUS **************************************************************** #
bonus:		$(BONUS)

${BONUS}:	${OBJ_BONUS}
	@printf "${BLUE}All objects bonus created!${RESET}\n"
	@cc ${FLAGS} -Iinclude ${OBJ_BONUS} -o $@ ${MLX}
	@printf "${GREEN}${NAME_BONUS} created!${RESET}\n"
	@exit 0

# CLEANING RULES ************************************************************* #
clean:
	@rm -fr ${OBJ}
	@rm -fr ${OBJ_BONUS}
	@printf "${YELLOW}All objects removed!${RESET}\n"

fclean:		clean
	@rm -fr ${NAME}
	@rm -fr ${NAME_BONUS}
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

.PHONY: all bonus clean fclean re