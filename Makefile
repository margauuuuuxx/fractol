# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 17:43:43 by marlonco          #+#    #+#              #
#    Updated: 2025/06/12 22:11:56 by marlonco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME    = fractol

# Compiler
CC      = gcc
CFLAGS  = -Werror -Wextra -Wall

# Architecture
UNAME_S    := $(shell uname -s)
ifeq ($(UNAME_S), Darwin) # macOS
    MLX_FLAGS	= -framework OpenGL -framework AppKit
    MLX_PATH	= minilibx/
else ifeq ($(UNAME_S), Linux)
    MLX_FLAGS	= -lX11 -lXext -lm -lbsd
	MLX_PATH	= minilibx-linux/
else 
	$(error Unsupported platform)
endif

# Minilibx
MLX_NAME   = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

# Include 
INC = 			-I ./include/\
				-I ./lib/libft/\
				-I ./lib/printf/\
				-I ./lib/$(MLX_PATH)

# Sources
SRC_PATH = src/
SRC      = color.c events.c init.c main.c rendering.c utils.c
SRCS     = $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH = obj/
OBJ      = $(SRC:.c=.o)
OBJS     = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(MLX):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) $(OBJS) $(INC) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "Fractol ready."

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
