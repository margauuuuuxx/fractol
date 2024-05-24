# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 17:43:43 by marlonco          #+#    #+#              #
#    Updated: 2024/05/24 16:50:25 by marlonco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	=	src/colouring.c src/fractol.c src/rendering.c
OBJS 	=	$(SRCS:.c=.o)
NAME 	=	fract-ol
CFLAGS 	= 	-Wall -Wextra -Werror
cc 		= 	gcc
INCLUDE =	include/fractol.h

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o) -I $(INCLUDE)

$(NAME): $(OBJS)
# to link with the required internal macOS API
	make all -C ./libft
	$(CC) $(CFLAGS) $(OBJ)	-L./libft -lft -Lmlx -lmlx -framework OpenGL -framework -AppKit -o $(NAME)

clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean:
	make clean -C ./libft
	rm -rf $(NAME)

re:
	fclean all

.PHONY:
	all, clean, fclean, re