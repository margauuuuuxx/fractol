/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:47:31 by marlonco          #+#    #+#             */
/*   Updated: 2025/06/12 20:38:36 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
scaling the coordinates system to see something
	x-axis: [-2 ; 2]
MANDELBROT:
	z = zˆ2 + c with:
				z initially (0,0i)
				c the actual point we want to check(a, bi)
JULIA:
	./fractol julia <cst.r> <cst.i>
	z = pixel point + cst
*/

static double	calculate_color(int i, int max)
{
	return ((int)(255.0 * i / max));
}

static void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	init_c(t_complex *z, t_complex *c, t_fractal *fract)
{
	if (ft_strncmp(fract->name, "julia", 5) == 0)
	{
		c->r = fract->julia_r;
		c->i = fract->julia_i;
	}
	else
	{
		c->r = z->r;
		c->i = z->i;
	}
}

/* using the modulus of z: |z| = cˆ2 = √(aˆ2 + bˆ2) if |z| > 2,
assume point escaped because of the domain restrictions
with c the escape radius */
static void	handle_pixel(int x, int y, t_fractal *fract)
{
	t_complex	z;
	t_complex	c;
	double		r_temp;
	int			i;

	i = 0;
	z.r = x * fract->zoom.zoom_x + fract->limit_x;
	z.i = y * fract->zoom.zoom_y + fract->limit_y;
	init_c(&z, &c, fract);
	while (i++ < fract->iterations_nbr
			&& (z.r * z.r + z.i * z.i) <= fract->escape_radius)
	{
		r_temp = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * z.r * z.i) + c.i;
		z.r = r_temp;
		
	}
	my_pixel_put(x, y, &fract->image, (i < fract->iterations_nbr) ? calculate_color(i, fract->iterations_nbr) : WHITE);
}

void	fractal_render(t_fractal *fract)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fract);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx_connection, fract->mlx_window,
		fract->image.image_ptr, 0, 0);
}
