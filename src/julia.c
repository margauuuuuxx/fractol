/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:32:46 by marlonco          #+#    #+#             */
/*   Updated: 2024/06/19 17:45:39 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			ft_julia(fractal);
			fractal->y++;	
		}
		fractal->x++;
		fractal->y = 0;
	}
}

void	ft_julia(t_fractal *fractal)
{
	int		i;
	double	temp;

	i = 0;
	fractal->name = "julia";
	fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
	while (i < fractal->max_iterations)
	{
		temp = fractal->zx;
		fractal->temp = pow(fractal->zx, 2) - pow(fractal->zy, 2) + fractal->cx;
		fractal->zy = 2 * fractal->zy * temp * fractal->cy;
		if (pow(fractal->zx, 2) + pow(fractal->zy, 2) >= __DBL_MAX__) // DBL MAX = max finite value of a double 
			break;
		i++;
	}
	if (i == fractal->max_iterations)
		ft_put_pixel(fractal, fractal->x, fractal->y, (t_RGB){0, 0, 0});
	else
		ft_put_pixel(fractal, fractal->x, fractal->y, (t_RGB){((i * 255) / fractal->max_iterations), ((i * 255) / fractal->max_iterations), ((i * 255) / fractal->max_iterations)});
}