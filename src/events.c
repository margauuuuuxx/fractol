/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:34:26 by marlonco          #+#    #+#             */
/*   Updated: 2025/06/13 10:08:24 by marlonco         ###   ########.fr       */
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

// 1 = scroll up
void	zoom(t_fractal *fract, int x, int y, int flag)
{
	if (flag == 1)
	{
		fract->limit_x += x * fract->zoom.zoom_x * (1 - 1 / 1.3);
		fract->limit_y += y * fract->zoom.zoom_y * (1 - 1 / 1.3);
		fract->zoom.zoom_x /= 1.3;
		fract->zoom.zoom_y /= 1.3;
		fract->iterations_nbr += 5;
	}
	else
	{
		fract->limit_x -= x * fract->zoom.zoom_x * (1 - 1.0 / 1.3);
		fract->limit_y -= y * fract->zoom.zoom_y * (1 - 1.0 / 1.3);
		fract->zoom.zoom_x *= 1.3;
		fract->zoom.zoom_y *= 1.3;
		if (fract->iterations_nbr > 30)
			fract->iterations_nbr -= 5;
	}
}

// on destroy: int (*f)(void *param)
int	close_handler(t_fractal *fract)
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
	else if (keysym == PLUS || keysym == PLUS_MB)
		zoom(fract, WIDTH / 2, HEIGHT / 2, 1);
	else if (keysym == MINUS || keysym == MINUS_MB)
		zoom(fract, WIDTH / 2, HEIGHT / 2, 0);
	else if (keysym == C)
		fract->color_scheme = (fract->color_scheme + 1) % 3;
	fractal_render(fract);
	return (0);
}

// mouse scroll: int (*f)(int button, int x, int y, void *param)
int	mouse_handler(int button, int x, int y, t_fractal *fract)
{
	if (button == SCROLL_UP)
		zoom(fract, x, y, 1);
	else if (button == SCROLL_DOWN)
		zoom(fract, x, y, 0);
	fractal_render(fract);
	return (0);
}
