/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:08:58 by marlonco          #+#    #+#             */
/*   Updated: 2024/05/21 17:57:15 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h> // for open
# include <unistd.h> // for close, read and write
# include <stdlib.h> // for malloc and exit
# include <errno.h> // for errno
# include <string.h> // for strerror 
# include <math.h> // maths fcts 
# include <mlx.h>

// strcut to write pixels for an image
typedef struct s_data {
	void	*image;
	char	*address;
	int		bpp; // = bites per pixel
	int		line_length;
	int		endian;
} t_data;

// struct for the imaginary and real part of complex numbers 
typedef struct s_complex {
    double real;
    double imaginary;
} t_complex;

typedef struct s_RGB {
    int r;
    int g;
    int b;
} t_RGB;


# endif 