# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 17:43:43 by marlonco          #+#    #+#              #
#    Updated: 2025/06/17 10:24:05 by marlonco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol
CC      = gcc
CFLAGS  = -Werror -Wextra -Wall

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

MLX_NAME   = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

INC = 			-I ./include/\
				-I ./lib/libft/\
				-I ./lib/printf/\
				-I ./lib/$(MLX_PATH)

SRC_PATH = src/
SRC      = color.c events.c init.c main.c rendering.c utils.c
SRCS     = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = obj/
OBJ      = $(SRC:.c=.o)
OBJS     = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(MLX):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)

$(NAME): $(OBJS) $(MLX)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) $(OBJS) $(INC) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "Fractol ready."

clean:
	@if [ -d "$(OBJ_PATH)" ]; then \
		echo "Removing .o object files..."; \
		rm -rf $(OBJ_PATH); \
	fi
	@if [ -f "$(MLX)" ] || [ -d "$(MLX_PATH)/obj" ]; then \
		echo "Removing MiniLibX .."; \
		make clean -C $(MLX_PATH); \
		rm -f $(MLX);\
	fi

fclean: clean
	@rm -f $(NAME); 

re: fclean all

.PHONY: all re clean fclean
