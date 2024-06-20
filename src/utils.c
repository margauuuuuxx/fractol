/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:36:17 by marlonco          #+#    #+#             */
/*   Updated: 2024/06/20 15:39:53 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

void	ft_put_pixel(t_fractal *fractal, int x, int y, int color)
{
	// int	**dest;
	// (void)color;
	// (void)y;
	// (void)x;
	
	// dest = (int **)malloc((SIZE * WIDTH) * sizeof(int *));
	// if (!dest)
	// {
	// 	return ;
	// }
	// *dest = fractal->ptr_to_image; // for the row & column offset
	
	// dest[0] = &color;

	char	*dest;
	
	dest = NULL;
	if (!(x < 0 || x > WIDTH) || !(y < 0 || y > SIZE))
	{
		//printf("fract adress ; %p\n fract line_lenght %d\n bpp %d\n", fractal->address, fractal->line_length, fractal->bpp);
		
		dest = fractal->address + (y * fractal->line_length + x * (fractal->bpp / 8)); 
		*(unsigned int *)dest = color;
	}
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
