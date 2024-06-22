/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:28:14 by marlonco          #+#    #+#             */
/*   Updated: 2024/06/22 14:44:00 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
This file has for objective to
*/

void	ft_viewport_fit(t_viewport *v) // EXPLIQUER CETTE FCT
{
	double	w;
	double	h;

	w = v->max - v->xmin;
	h = v->ymax - v->ymin;
	if (w / h >= (float)WIDTH / HEIGHT)
	{
		v->ymin = -(w * HEIGHT / WIDTH / 2);
		v->ymax = w * HEIGHT / WIDTH / 2;
	}
	else
	{
		v->xmin = -(h * WIDTH / HEIGHT / 2);
		v->xmax = (h * WIDTH / HEIGHT / 2);
	}
}

void	ft_viewport_init(t_mlx *mlx)
{
	mlx->viewport->offsetx = 0;
	mlx->viewport->offsety = 0;
	mlx->fractal->viewport(&mlx->viewport); // TF ????????
	ft_viewport_fit(&mlx->viewport);
}

t_complex	ft_complex_conversion(int x, int y, t_viewport *v)
{
	t_complex	c;
	c.r = ((double)x / WIDTH) * (v->xmax - v->xmin) * v->zoom + v->xmin + v->offsetx;
	c.i = ((double)y / HEIGHT) * (v->ymax - v->ymin) *v->zoom + v->ymin + v->offsety;
	return (c);
}