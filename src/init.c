/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:24:33 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/29 14:38:31 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#define KEY_PRESS 2
#define KEY_RELEASE 3
#define SCROLL_UP 4
#define SCROLL_DOWN 5
#define MOUSE_MOVE 6    // MotionNotify
#define REDRAW 12       // ON_EXPOSE
#define CLOSE_WINDOW 17 // clicking on the x of the window

/*
Key objectives:
	1) Initialize mlx ;
	2) Listening events ;
	3) Hooks data
*/

static void	malloc_error(void)
{
	perror("Malloc error\n");
	exit(EXIT_FAILURE);
}

// escape radius = 4 = 2^2 --> useful for rendering
static void	data_init(t_fractal *fract)
{
	fract->escape_radius = 4;
	fract->iterations_nbr = 100;
	fract->zoom_factor = 1.0;
	fract->limit_x = 0.0;
	fract->limit_y = 0.0;
}

static void	events_init(t_fractal *fract)
{
	mlx_hook(fract->mlx_window, KEY_PRESS, 0, key_handler, fract);
	mlx_hook(fract->mlx_window, SCROLL_UP, 0, mouse_handler, fract);
	mlx_hook(fract->mlx_window, CLOSE_WINDOW, 0, close_handler, fract);
	mlx_hook(fract->mlx_window, MOUSE_MOVE, 0, track_julia, fract);
}

void	fractal_init(t_fractal *fract)
{
	fract->mlx_connection = mlx_init();
	if (fract->mlx_connection == NULL)
		malloc_error();
	fract->mlx_window = mlx_new_window(fract->mlx_connection, WIDTH, HEIGHT,
			fract->name);
	if (fract->mlx_window == NULL)
	{
		mlx_destroy_window(fract->mlx_connection, fract->mlx_window);
		free(fract->mlx_connection);
		malloc_error();
	}
	fract->image.image_ptr = mlx_new_image(fract->mlx_connection, WIDTH,
			HEIGHT);
	if (fract->image.image_ptr == NULL)
	{
		mlx_destroy_window(fract->mlx_connection, fract->mlx_window);
		free(fract->mlx_connection);
		malloc_error();
	}
	fract->image.pixels_ptr = mlx_get_data_addr(fract->image.image_ptr,
			&fract->image.bpp, &fract->image.line_length, &fract->image.endian);
	events_init(fract);
	data_init(fract);
}
