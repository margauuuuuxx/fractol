/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:27:49 by marlonco          #+#    #+#             */
/*   Updated: 2024/06/24 10:45:26 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_pixel    ft_mandelbrot(int x, int y, t_viewport *v, t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int			i;

	(void)mlx;
	i = 0;
    z = ft_complex_conversion(x, y, v);
	c = ft_complex_conversion(x, y,v);
    while (pow(z.r, 2) + pow(z.i, 2) < 256 && i < v->max)
    {
        temp.r = pow(z.r, 2) - pow(z.i, 2) + c.r;
        temp.i = 2 * z.r * z.i + c.i;
		if (z.r == temp.r && z.i == temp.i)
		{
			i = v->max;
			break;
		}
		z.r = temp.r;
		z.i = temp.i;
    	i++;
    }
	return ((t_pixel){.c = z, .i = i});
}

void	ft_mandelbrot_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -1.0f;
	v->ymax = 1.0f;
	v->offsetx = -0.5f;
}