/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:27:49 by marlonco          #+#    #+#             */
/*   Updated: 2024/06/20 15:43:32 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	*ft_draw_mandelbrot(void *fractal_void)
{
	t_fractal	*fractal;
	
	fractal = (t_fractal *)fractal_void;
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < WIDTH)
	{
		while (fractal->y < SIZE)
		{
			ft_mandelbrot(fractal);
			fractal->y++;	
		}
		fractal->x++;
		fractal->y = 0;
	}
	return (NULL);
}

void    ft_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	temp;

	i = 0;
    fractal->name = "mandelbrot";
    fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	
    while (i < fractal->max_iterations)
    {
        temp = pow(fractal->zx, 2) - pow(fractal->zy, 2) + fractal->cx;
        fractal->zy = 2 * fractal->zx * fractal->zy + fractal->cy;
        fractal->zx = temp;
		if (pow(fractal->zx, 2) + pow(fractal->zy, 2) >= __DBL_MAX__)
			break;
    	i++;
    }
	if (i == fractal->max_iterations)
		ft_put_pixel(fractal, fractal->x, fractal->y, 0x000000); 
	else
		ft_put_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i % 255)));
}