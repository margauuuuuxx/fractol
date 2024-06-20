/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:36:17 by marlonco          #+#    #+#             */
/*   Updated: 2024/06/20 12:55:30 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_put_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	        *dest;
   // unsigned int    color_int;

    //color_int = (color.r << 16) | (color.g << 8) | color.b; //then the int is in format 0xRRGGBB
	dest = fractal->ptr_to_image; // for the row & column offset
	dest[(y * fractal->line_length / 4) + x] = color;
}

double	generate_random_c(void)
{
	return(((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

void	set_random_julia(double *cx, double *cy)
{
	*cx = generate_random_c();
	*cy = generate_random_c();
}

void	ft_change_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == M)
	{
		if (fractal->max_iterations > 42)
			fractal->max_iterations -= 42;
	}
	else if (key_code == P)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}
