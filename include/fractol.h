/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:08:58 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/29 14:45:46 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 400

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
	char	*pixels_ptr;
	int		bpp;
	int		line_length;
	// number of bytes per row of the image (also called stride)
	int		endian;
}			t_image;

// fractal struct
typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	t_image	image;
	char	*name;
	double	escape_radius;
	int		iterations_nbr;
	double	zoom_factor;
	double	julia_r;
	double	julia_i;
	double	limit_x;
	double	limit_y;
}			t_fractal;

// events
int			close_handler(t_fractal *fract);
int			key_handler(int keysym, t_fractal *fract);
int			mouse_handler(int button, int x, int y, t_fractal *fract);
int			track_julia(int x, int y, t_fractal *fract);

// init
void		fractal_init(t_fractal *fract);

// rendering
double		map(double unscaled_nbr, double new_min,
				double new_max,	double old_max);
void		fractal_render(t_fractal *fract);

// utils
int			ft_strncmp(const char *s, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
double		atoi_dbl(char *str);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);

#endif