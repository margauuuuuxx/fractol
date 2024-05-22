# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 17:43:43 by marlonco          #+#    #+#              #
#    Updated: 2024/05/21 17:47:19 by marlonco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# to compile with mlx 
%.o: %.c 
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@ 

# to link with the required internal macOS API
$(CC) $(OBJ)	-Lmlx -lmlx -framework OpenGL -framework -AppKit -o $(NAME)