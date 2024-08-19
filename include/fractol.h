/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:08:58 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/18 15:56:24 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

// # include <fcntl.h> 
# include <unistd.h> 
# include <stdlib.h> 
// # include <errno.h> 
# include <string.h> 
# include <math.h> 
# include <stdio.h>
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/printf/includes/ft_printf.h"

# define WIDTH 1920
# define HEIGHT 1080
# define ZOOM 1.0f

// key codes
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124


// mouse codes 
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define MOUSE_CURSOR 6 

// complex number struct
typedef struct	s_complex {
	double	r;
	double	i;
}	t_complex;

// image struct (from mlx_get_data_addr())
typedef struct	s_image {
	void	*image_ptr;
	char	*pixels_ptr; // pointing to 1 byte
	int		bpp;
	int		line_length; // number of bytes per row of the image (also called stride)
	int		endian;
}	t_image;

// fractal struct
typedef struct s_fractal
{
	void	*mlx_connection; // mlx_init()
	void	*mlx_window; // mlx_new_window()
	t_image	image;
	char	*name;
	double	escape_radius;
	int		iterations_nbr;
	double	shift_x;
	double	shift_y;
	double	zoom_factor;
	double	julia_r;
	double	julia_i;
}	t_fractal;


// hook
int		key_hook(int key_code, t_mlx *mlx);
void	ft_zoom(int x, int y, t_viewport *v, double z);
int		hook_mousemovement(int mouse_code, int x, int y, t_mlx *mlx);
int		hook_mouseend(int mouse_code, t_mlx *mlx);
int		hook_mousecursor(int x, int y, t_mlx *mlx);
int		exit_fractal(t_fractal *fractal);

// int
t_image	*ft_del_image(t_mlx *mlx, t_image *image);
t_image	*ft_new_image(t_mlx *mlx);
t_mlx	*ft_deletemlx(t_mlx *mlx);
t_mlx	*ft_mlx_init(t_fractal * fractal);

// julia
t_pixel	ft_julia(int x, int y, t_viewport *v, t_mlx *mlx);
void	ft_julia_viewport(t_viewport *v);

// main
int		ft_name_check(char *name);
int		ft_die(char *reason);

// mandelbrot
t_pixel	ft_mandelbrot(int x, int y, t_viewport *v, t_mlx *mlx);
void	ft_mandelbrot_viewport(t_viewport *v);

// rendering
void	*ft_render_thread(void *args);
void	ft_draw(t_mlx *mlx);
void	ft_render(t_mlx *mlx);

// utils 
void	ft_put_pixel(t_fractal *fractal, int x, int y, int color);
double	generate_random_c(void);
void	set_random_julia(double *cx, double *cy);
void	ft_change_iterations(t_fractal *fractal, int key_code);

// viewport
void		ft_viewport_fit(t_viewport *v);
void		ft_viewport_init(t_mlx *mlx);
t_complex	ft_complex_conversion(int x, int y, t_viewport *v);

# endif 