/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:08:58 by marlonco          #+#    #+#             */
/*   Updated: 2024/06/20 15:13:46 by marlonco         ###   ########.fr       */
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
# include "../lib/printf/includes/ft_printf.h"
# include "../lib/libft/libft.h"

# define SIZE 1080
# define WIDTH 1920

// key codes
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46

// mouse codes 
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// struct for the imaginary and real part of complex numbers and struct to write pixels for an image
typedef	struct s_fractal {
	void	*image;
	void	*ptr_to_image;
	void	*mlx;
	void	*window;
	void	*address;
	int		color;
	int		x;
	int		y;
	int		iterations;
	int		max_iterations;
	int		bpp; // = bites per pixel
	int		endian;
	int		line_length;
	char	*name;
	double	offset_x;
	double	offset_y;
	double	zoom;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	temp;
} t_fractal;

// struct for color gradient 
typedef struct s_RGB {
    int r;
    int g;
    int b;
} t_RGB;

// hook
int		key_hook(int key, t_fractal *fractal);
void	ft_zoom(t_fractal *fractal, int x, int y, int flag);
int		mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);
int		exit_fractal(t_fractal *fractal);

// julia
void	ft_draw_julia(t_fractal *fractal);
void	ft_julia(t_fractal *fractal);

// main
//int		name_validity(char *argv, t_fractal *fractal);
int		ft_draw_fractal(t_fractal *fractal, char *type);
void	fractal_initialization(t_fractal *fractal);
void	mlx_initialization(t_fractal *fractal);

// mandelbrot
void	*ft_draw_mandelbrot(void *fractal_void);
void	ft_mandelbrot(t_fractal *fractal);

// utils 
void	ft_put_pixel(t_fractal *fractal, int x, int y, int color);
double	generate_random_c(void);
void	set_random_julia(double *cx, double *cy);
void	ft_change_iterations(t_fractal *fractal, int key_code);

# endif 