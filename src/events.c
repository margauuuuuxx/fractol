/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:34:26 by marlonco          #+#    #+#             */
/*   Updated: 2025/06/12 19:15:37 by marlonco         ###   ########.fr       */
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
		fract->limit_x += (0.5 * fract->zoom_factor);
	else if (keysym == LEFT)
		fract->limit_x -= (0.5 * fract->zoom_factor);
	else if (keysym == DOWN)
		fract->limit_y -= (0.5 * fract->zoom_factor);
	else if (keysym == UP)
		fract->limit_y += (0.5 * fract->zoom_factor);
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
	double	ratio;
	double	lx;
	double	ly;

	ratio = (double)WIDTH / HEIGHT;
	if (button == SCROLL_UP)
	{
		lx = (map(x, -2 * ratio, 2 * ratio, WIDTH) * fract->zoom_factor);
		fract->limit_x += lx;
		ly = (map(y, 2, -2, HEIGHT) * fract->zoom_factor);
		fract->limit_y += ly;
		fract->zoom_factor /= 1.3;
		fractal_render(fract);
	}
	else if (button == SCROLL_DOWN)
	{
		fract->zoom_factor *= 1.05;
		fractal_render(fract);
	}
	return (0);
}

// mouse movement (pointer): int (*f)(int x, int y, void *param)
int	track_julia(int x, int y, t_fractal *fract)
{
	if (ft_strncmp(fract->name, "julia", 5))
	{
		fract->julia_r = (map(x, -2, 2, WIDTH)) * fract->zoom_factor
			+ fract->limit_x;
		fract->julia_i = (map(y, 2, -2, HEIGHT)) * fract->zoom_factor
			+ fract->limit_y;
	}
	fractal_render(fract);
	return (0);
}
