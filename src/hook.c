/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:29:12 by marlonco          #+#    #+#             */
/*   Updated: 2024/06/22 15:19:35 by marlonco         ###   ########.fr       */
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
int key_hook(int key_code, t_mlx *mlx)
{
	double	w;
	double	h;

	w = (mlx->viewport->xmax - mlx->viewport->xmin) * (mlx->viewport->zoom);
	h = (mlx->viewport->ymax - mlx->viewport->ymin) * (mlx->viewport->zoom);
	if (key_code == ESC)
		exit(1);
	else if (key_code == LEFT)
		mlx->viewport->offsetx -= w * 0.05f; // arbitrary 0.05 float value, why float ? less memory needed
	else if (key_code == RIGHT)
		mlx->viewport->offsetx += w * 0.05f;
	else if (key_code == UP)
		mlx->viewport->offsety -= h * 0.05f;
	else if (key_code == DOWN)
		mlx->viewport->offsety += h * 0.05f;
	/*
	else if (key_code == R)
		fractal_initialization(fractal);
	else if (key_code == C)
		mlx->fractal->color += (255 * 255 * 255) / 100; // max value of RGB / 100
	else if (key_code == J)
		set_random_julia(&fractal->cx, &fractal->cx);
	else if (key_code == M || key_code == P)
		ft_change_iterations(fractal, key_code);
	ft_draw_fractal(fractal, fractal->name);
	*/
	return (0);	
}
/*
SCROLL_UP = zoom in
SCROLL_DOWN = zoom out
Let x and y be the coordinates of the mouse 
*/

void	ft_zoom(int	x, int y, t_viewport *v, double z)
{
	double	w;
	double	h;
	double	nw;
	double	nh;

	w = (v->xmax - v->xmin) * (v->zoom);
	h = (v->ymax - v->ymin) * (v->zoom);
	nw = (v->xmax - v->xmin) * (v->zoom * z);
	nh = (v->ymax = v->ymax) * (v->zoom * z);
	v->zoom *= z;
	v->offsetx -= ((double)x / WIDTH) * (nw - w); // x / W = relative position ; (nw - w) = the changue due to the zoom
	v->offsety -= ((double)y / HEIGHT) * (nh - h);
}

int	hook_mousemovement(int mouse_code, int x, int y, t_mlx *mlx)
{
	if (mouse_code == SCROLL_UP)
	{
		ft_zoom(x, y, mlx->viewport, ZOOM); // avant c'etait &mlx->viewport
		ft_render(mlx);
	}
	if (mouse_code == SCROLL_DOWN)
	{
		ft_zoom(x, y, mlx->viewport, ZOOM); // pareil
		ft_render(mlx);
	}
	if (y < 0)
		return (0);
	mlx->mouse.isdown |= 1 << mouse_code; // to update the mose button by binary bit operation 
	return (0);
}

//fct for when the mouse button is no longer pressed 
int	hook_mouseend(int mouse_code, t_mlx *mlx)
{
	mlx->mouse.isdown &= ~(1 << mouse_code); // resets the status of the mouse action to 0
	return (0);
}

int	hook_mousecursor(int x, int y, t_mlx *mlx)
{
	double	w;
	double	h;

	mlx->mouse.lastx = mlx->mouse.x;
	mlx->mouse.lasty = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (!mlx->mouselock)
		mlx->viewport->mouse = ft_complex_conversion(x, y, mlx->viewport); // avant ct &mlx->viewport
	if (mlx->mouse.isdown & (1 << 1)) // check if the second bit is 1 if yes that will mean that the right mouse button is pressed
	{
			w = (mlx->viewport->xmax - mlx->viewport->xmin) * mlx->viewport->zoom;
			h = (mlx->viewport->ymax - mlx->viewport->ymin) * mlx->viewport->zoom;
			mlx->viewport->offsetx += (double)(mlx->mouse.lastx - mlx->mouse.x) / WIDTH * w;
			mlx->viewport->offsetx += (double)(mlx->mouse.lasty - mlx->mouse.y) / HEIGHT * h;	
	}
	if (mlx->mouse.isdown || (mlx->fractal->mouse && !mlx->mouselock))
		ft_render(mlx);
	return (0);
}

/*
int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	exit (1);
	return (0);
}
*/