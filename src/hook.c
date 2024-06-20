/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:29:12 by marlonco          #+#    #+#             */
/*   Updated: 2024/06/20 14:00:42 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
This file has for objectives to define the different hooks callback functions
*/

/*
R = reset the fractal
C = change the color scheme
J = set the constant of Julia to random valus
P = increase the max iterations
M = reduce the max iterations
*/
int key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit(1);
	else if (key_code == LEFT)
		fractal->offset_x -= 42 / fractal->zoom; // arbitrary 42 value 
	else if (key_code == RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == R)
		fractal_initialization(fractal);
	else if (key_code == C)
		fractal->color += (255 * 255 * 255) / 100; // max value of RGB / 100
	else if (key_code == J)
		set_random_julia(&fractal->cx, &fractal->cx);
	else if (key_code == M || key_code == P)
		ft_change_iterations(fractal, key_code);
	ft_draw_fractal(fractal, fractal->name);
	return (0);	
}
/*
SCROLL_UP = zoom in
SCROLL_DOWN = zoom out
Let x and y be the coordinates of the mouse 
*/

void	ft_zoom(t_fractal *fractal, int x, int y, int flag)
{
	double	zoom; // store the factor by which the fractal is zoomed in/out

	zoom = 1.42; // arbitrary choice 
	if (flag == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom * zoom));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y / (fractal->zoom * zoom));
		fractal->zoom *= zoom;
	}
	else if (flag == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom / zoom));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom / zoom));
		fractal->zoom /= zoom;
	}
	else 
		return;
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		ft_zoom(fractal, x, y, 1);
	if (mouse_code == SCROLL_DOWN)
		ft_zoom(fractal, x, y, -1);
	ft_draw_fractal(fractal, fractal->name);
	return (0);
}

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	exit (1);
	return (0);
}