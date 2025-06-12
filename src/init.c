/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:24:33 by marlonco          #+#    #+#             */
/*   Updated: 2025/06/12 21:43:23 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
Key objectives:
	1) Initialize mlx ;
	2) Listening events ;
	3) Hooks data
*/

static void	malloc_error(void)
{
	perror("Malloc Failure\n");
	exit(EXIT_FAILURE);
}

static void	zoom_init(t_zoom *zoom, double aspect)
{
	zoom->zoom_factor = 1.0;
	zoom->zoom_x = (2.0 * aspect * zoom->zoom_factor) / WIDTH;
	zoom->zoom_y = (-2.0 * zoom->zoom_factor) / HEIGHT;
}

// escape radius = 4 = 2^2 --> useful for rendering
static void	data_init(t_fractal *fract)
{
	fract->escape_radius = 4;
	fract->iterations_nbr = 100;
	fract->aspect = (double)WIDTH / (double)HEIGHT;
	zoom_init(&fract->zoom, fract->aspect);
	fract->limit_x = -WIDTH / 2.0 * fract->zoom.zoom_x;
	fract->limit_y = -HEIGHT / 2.0 * fract->zoom.zoom_y;
	fract->color_scheme = 0;
}

static void	events_init(t_fractal *fract)
{
	mlx_hook(fract->mlx_window, KEY_PRESS, 0, key_handler, fract);
	mlx_hook(fract->mlx_window, SCROLL_UP, 0, mouse_handler, fract);
	mlx_hook(fract->mlx_window, CLOSE_WINDOW, 0, close_handler, fract);
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
