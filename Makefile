# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 17:43:43 by marlonco          #+#    #+#              #
#    Updated: 2024/06/20 14:35:21 by marlonco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRCS 	=	src/hook.c src/julia.c src/main.c src/mandlbrot.c src/utils.c
# OBJS 	=	$(SRCS:.c=.o)
# NAME 	=	fract-ol
# CFLAGS 	= 	-Wall -Wextra -Werror
# CC 		= 	gcc
# INCLUDE =	include/fractol.h

# LIBFT_PATH = lib/libft/
# PRINTF_PATH = lib/printf/
# MLX_PATH = lib/minilibx/

# LIBFT = $(LIBFT_PATH)/libft.a
# PRINTF = $(PRINTF_PATH)/libftprintf.a
# MLX = $(MLX_PATH)/libmlx.a

# all: $(NAME) $(MLX) $(LIBFT) $(PRINTF)

# # %.o: %.c
# # 	$(CC) $(CFLAGS) -Imlx -c $< -o $@ -I $(INCLUDE)

# # $(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
# # # to link with the required internal macOS API
# # # make all -C ./libft
# # 	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lftprintf -L$(MLX_PATH)	-lmlx -framework OpenGL -framework -AppKit 

# # $(LIBFT):
# # 	make -C $(LIBFT_PATH)
	
# # $(PRINTF):
# # 	make -C $(PRINTF_PATH)

# # $(MLX):
# # 	make -C $(MLX_PATH)

# $(OBJS):
# 	@$(CC) $(CFLAGS) -c $(@:.o=.c)

# $(NAME): $(OBJS)
# 	@$(MAKE) -C $(LIBFT_PATH)
# 	@$(MAKE) -C $(PRINTF_PATH)
# 	@$(MAKE) -C $(MLX_PATH)
# 	@$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(MLX) $(OBJS) -o $(NAME) -lmlx -framework OpenGL -framework -AppKit 

# clean:
# 	make clean -C $(LIBFT_PATH)
# 	make clean -C $(PRINTF_PATH)
# 	make clean -C $(MLX_PATH)
# 	rm -rf $(OBJS)

# fclean:
# 	make clean -C $(LIBFT_PATH)
# 	make clean -C $(PRINTF_PATH)
# 	make clean -C $(MLX_PATH)
# 	rm -rf $(NAME)

# re:
# 	fclean all

# .PHONY:
# 	all, clean, fclean, re

#Program name
NAME	= fractol

# Compiler
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall -g3

# Minilibx
# MLX_PATH	= ./lib/minilibx
# MLX_NAME	= libmlx.a
# MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= ./lib/libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Printf
PRINTF_PATH = ./lib/printf/
PRINTF_NAME = libftprintf.a
PRINTF		= $(PRINTF_PATH)$(PRINTF_NAME)

# Includes
INC			=	-I ./include/\
				-I ./lib/libft/\
				-I ./lib/printf/\
				-I ./lib/minilibx/

# Sources
SRC_PATH	=	src/
SRC			=	hook.c julia.c main.c mandelbrot.c utils.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(PRINTF) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

# $(MLX):
# 	@echo "Making MiniLibX..."
# 	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

$(PRINTF):
	@echo "Making printf..."
	@make -sC $(PRINTF_PATH)

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@$(CC) -fsanitize=address -g3 $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF) $(INC) -lmlx -framework OpenGL -framework AppKit 
	@echo "Fractol ready."

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
# @make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(PRINTF_PATH)

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@$(MAKE) fclean -C $(PRINTF_PATH)

re: fclean all

.PHONY: all re clean fclean