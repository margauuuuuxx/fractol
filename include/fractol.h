/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:08:58 by marlonco          #+#    #+#             */
/*   Updated: 2025/06/12 21:43:06 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "includes.h"

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
	int		line_length; // number of bytes per row of the image (also called stride)
	int		endian;
}			t_image;

typedef struct s_zoom
{
	double	zoom_factor;
	double	zoom_x;
	double	zoom_y;
}	t_zoom;

// fractal struct
typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	t_image	image;
	char	*name;
	double	escape_radius;
	int		iterations_nbr;
	double	julia_r;
	double	julia_i;
	double	limit_x;
	double	limit_y;
	double	aspect;
	int		color_scheme;
	t_zoom	zoom;
}			t_fractal;

// color
int			calculate_color(int i, int max, int scheme);

// events
int			close_handler(t_fractal *fract);
int			key_handler(int keysym, t_fractal *fract);
int			mouse_handler(int button, int x, int y, t_fractal *fract);

// init
void		fractal_init(t_fractal *fract);

// rendering
void		fractal_render(t_fractal *fract);

// utils
int			ft_strncmp(const char *s, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
double		atoi_dbl(char *str);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
