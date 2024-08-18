/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:08:58 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/18 13:58:52 by marlonco         ###   ########.fr       */
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
# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46

// mouse codes 
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define MOUSE_CURSOR 6

typedef struct s_mlx	t_mlx; // we define it here because we need t_mlx in t_thread but we need t_thread in t_mlx 

// complex number struct
typedef struct	s_complex {
	double	r;
	double	i;
}	t_complex;

// viewport struct
typedef struct	s_viewport {
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		zoom;
	double		offsetx;
	double		offsety;
	long		max;
	t_complex	mouse;
}	t_viewport;

// pixel struct 
typedef struct s_pixel {
	t_complex	c;
	long		i;
}	t_pixel;

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
}	t_fractal;

// mouse struct
typedef struct 	s_mouse {
	char	isdown;
	int		x;
	int		y;
	int		lastx;
	int		lasty;
}	t_mouse;

// palette struct
typedef struct s_palette {
	uint8_t	count; // since the max value of count is 16, we use this data type, ranging from 0 to 255 for more efficient memory allocation (only use 1 bite VS an int use 4)
	int		cycle;
	int		colors[16];
}	t_palette;

// struct for color gradient 
typedef struct s_color_RGB {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} t_color_RGB;

// render struct
typedef struct s_thread {
	int		id;
	t_mlx	*mlx;
}	t_thread;

typedef struct s_render {
	pthread_t	threads[THREADS];
	t_thread	args[THREADS];
}	t_render;

// mlx struct 
typedef struct s_mlx {

	void		*mlx;
	void		*window;
	t_fractal	*fractal;
	t_pixel		*data;
	t_image		*image;
	t_mouse		mouse;
	t_viewport	*viewport;
	t_color_RGB	color;
	t_render	*render;
	int			smooth;
	int			mouselock;
}	t_mlx;

// struct for color gradient 
typedef struct s_RGB {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} t_RGB;

// struct for color
typedef union u_color { //union is when all the components share the same memory so you can access only 1 value at a time
	int	value;
	t_RGB	rgb;
}	t_color;

// colouring
void		ft_set_pixel(t_image *image, int x, int y,int color);
t_color_RGB	ft_color_init(void);

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