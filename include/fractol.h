/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:08:58 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/26 16:09:28 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// # include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
// # include <errno.h>
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <string.h>

# define WIDTH 1920
# define HEIGHT 1080

// complex number struct
typedef struct s_complex
{
	double	r;
	double	i;
}			t_complex;

// image struct (from mlx_get_data_addr())
typedef struct s_image
{
	void	*image_ptr;
	char *pixels_ptr; // pointing to 1 byte
	int		bpp;
	int		line_length;
	// number of bytes per row of the image (also called stride)
	int		endian;
}			t_image;

// fractal struct
typedef struct s_fractal
{
	void *mlx_connection; // mlx_init()
	void *mlx_window;     // mlx_new_window()
	t_image	image;
	char	*name;
	double	escape_radius;
	int		iterations_nbr;
	double	shift_x;
	double	shift_y;
	double	zoom_factor;
	double	julia_r;
	double	julia_i;
}			t_fractal;

// events
int			close_handler(t_fractal *fract);
int			key_handler(int keysym, t_fractal *fract);
int			mouse_handler(int button, int x, int y, t_fractal *fract);
int			track_julia(int x, int y, t_fractal *fract);

// init
void		fractal_init(t_fractal *fract);

// rendering
void		fractal_render(t_fractal *fract);

// utils
double		map(double unscaled_nbr, double new_min, double new_max,
				double old_min, double old_max);
int			ft_strncmp(const char *s, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
double		atoi_dbl(char *str);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);

#endif