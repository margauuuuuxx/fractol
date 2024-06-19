# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 17:43:43 by marlonco          #+#    #+#              #
#    Updated: 2024/06/19 17:35:48 by marlonco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	=	src/hook.c src/julia.c src/main.c src/mandlbrot.c src/utils.c
OBJS 	=	$(SRCS:.c=.o)
NAME 	=	fract-ol
CFLAGS 	= 	-Wall -Wextra -Werror
CC 		= 	gcc
INCLUDE =	include/fractol.h

LIBFT_PATH = lib/libft
PRINTF_PATH = lib/printf
MLX_PATH = lib/minilibx

LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a
MLX = $(MLX_PATH)/libmlx.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ -I $(INCLUDE)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
# to link with the required internal macOS API
# make all -C ./libft
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lftprintf -L$(MLX_PATH)	-lmlx -framework OpenGL -framework -AppKit 

$(LIBFT):
	make -C $(LIBFT_PATH)
	
$(PRINTF):
	make -C $(PRINTF_PATH)

$(MLX):
	make -C $(MLX_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(PRINTF_PATH)
	make clean -C $(MLX_PATH)
	rm -rf $(OBJS)

fclean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(PRINTF_PATH)
	make clean -C $(MLX_PATH)
	rm -rf $(NAME)

re:
	fclean all

.PHONY:
	all, clean, fclean, re