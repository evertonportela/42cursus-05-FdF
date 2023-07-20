# Compilation and Flags
CC			=	cc
#FLAGS		= 	-Wall -Wextra -Werror
FLAGS		= 	


# Libraries
INCLUDES	= 	-I./lib/mlx/mlx-linux
LIBRARY		=	-L./lib/mlx/mlx-linux

# Generate objects rule
%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -Imlx_linux -O3 -c $< -o $@

# Library Name
NAME		= fract-ol.a

# Source Files
SOURCES		= fract-ol.c

# Objects File
OBJ			= $(SOURCES:%.c=%.o)

# Generate Library Rule
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux $(LIBRARY) -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# Variables delete files
RM			= rm -f

# Delete Files Rules
clean:
	$(RM) $(OBJ)
fclean:		clean
	$(RM) $(NAME)

# Execute Test Code
test:
	clear
	make fclean
	make
	./fract-ol.a