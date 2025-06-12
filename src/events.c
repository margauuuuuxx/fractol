/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:34:26 by marlonco          #+#    #+#             */
/*   Updated: 2025/06/12 20:36:04 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
KEYCODE VS KEYSYM:
	* keycode = represent a specific key on the keyboard,
		usually represented by a numeric value
	* keysym (key symbol) = maps specific char/fcts of keys 
        independent of the keyboard layout/hardware specifics
*/

// on destroy: int (*f)(void *param)
int	close_handler(t_fractal *fract)
		// how to do it for when i go to the X with my mouse !!!!
{
	mlx_destroy_image(fract->mlx_connection, fract->image.image_ptr);
	mlx_destroy_window(fract->mlx_connection, fract->mlx_window);
	free(fract->mlx_connection);
	exit(EXIT_SUCCESS);
}

// keypress: int (*f)(int keycode, void *param)
int	key_handler(int keysym, t_fractal *fract)
{
	if (keysym == ESC)
		close_handler(fract);
	else if (keysym == RIGHT)
		fract->limit_x += 50 * fract->zoom.zoom_x;
	else if (keysym == LEFT)
		fract->limit_x -= 50 * fract->zoom.zoom_x;
	else if (keysym == DOWN)
		fract->limit_y -= 50 * fract->zoom.zoom_y;
	else if (keysym == UP)
		fract->limit_y += 50 * fract->zoom.zoom_y;
	else if (keysym == PLUS)
		fract->iterations_nbr += 10;
	else if (keysym == MINUS)
		fract->iterations_nbr -= 10;
	fractal_render(fract);
	return (0);
}

// mouse scroll: int (*f)(int button, int x, int y, void *param)
int	mouse_handler(int button, int x, int y, t_fractal *fract)
{
	if (button == SCROLL_UP)
	{
		fract->limit_x += x * fract->zoom.zoom_x * (1 - 1 / 1.3);
		fract->limit_y += y *fract->zoom.zoom_y * (1 - 1 / 1.3);
		fract->zoom.zoom_x /= 1.3;
		fract->zoom.zoom_y /= 1.3;
		fractal_render(fract);
	}
	else if (button == SCROLL_DOWN)
	{
		fract->limit_x -= x * fract->zoom.zoom_x * (1 - 1.0 / 1.05);
		fract->limit_y -= y *fract->zoom.zoom_y * (1 - 1.0 / 1.05);
		fract->zoom.zoom_x *= 1.05;
		fract->zoom.zoom_y *= 1.05;
		fractal_render(fract);
	}
	return (0);
}

// mouse movement (pointer): int (*f)(int x, int y, void *param)
int	track_julia(int x, int y, t_fractal *fract)
{
	if (ft_strncmp(fract->name, "julia", 5))
	{
		fract->julia_r = x * fract->zoom.zoom_x + fract->limit_x;
		fract->julia_i = y * fract->zoom.zoom_y + fract->limit_y;
		fractal_render(fract);
	}
	return (0);
}
