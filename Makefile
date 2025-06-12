# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 17:43:43 by marlonco          #+#    #+#              #
#    Updated: 2025/06/12 19:07:02 by marlonco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME    = fractol

# Compiler
CC      = gcc
CFLAGS  = -Werror -Wextra -Wall

# # Architecture
# ARCH    := $(shell uname -m)
# ifeq ($(ARCH), arm64)
#     # For Mac Silicon (ARM architecture)
#     MLX_FLAGS = -L/opt/homebrew/opt/glfw/lib -lglfw -L$(MLX_PATH) -lmlx
#     INC       = -I./include -I/opt/homebrew/opt/glfw/include -I$(MLX_PATH)
# # else
#     # For Mac Intel (x86_64 architecture)
#     MLX_FLAGS = -L$(MLX_PATH) -lmlx -Lmlx
#     INC       = 	-I./include/\
# 					-I$(MLX_PATH)
# endif

# Minilibx
MLX_PATH   = minilibx/
MLX_NAME   = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

# Include 
INC = 			-I ./include/\
				-I ./lib/libft/\
				-I ./lib/printf/\
				-I ./lib/minilibx/

# Sources
SRC_PATH = src/
SRC      = events.c init.c main.c rendering.c utils.c
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
	@make -sC $(MLX_PATH) 2>/dev/null

# $(NAME): $(OBJS)
# 	@echo "Compiling fractol..."
# 	@$(CC) -fsanitize=address $(CFLAGS) $(OBJS) $(INC) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# 	@echo "Fractol ready."

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@$(CC) -fsanitize=address $(CFLAGS) $(OBJS) $(INC) $(MLX) -framework OpenGL -framework AppKit -o $(NAME)
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
