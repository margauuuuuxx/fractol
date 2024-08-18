/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:47:31 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/18 15:44:29 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#define BLACK         0x000000
#define WHITE         0xFFFFFF
#define BRIGHT_WHITE  0xF5F5F5

#define RED           0xFF007F
#define BRIGHT_RED    0xFF3366

#define GREEN         0x00FF7F
#define BRIGHT_GREEN  0x33FF66

#define YELLOW        0xFFFF00
#define BRIGHT_YELLOW 0xFFFF66

#define BLUE          0x7F00FF
#define BRIGHT_BLUE   0x6666FF

#define MAGENTA       0xFF00FF
#define BRIGHT_MAGENTA 0xFF66FF

#define CYAN          0x00FFFF
#define BRIGHT_CYAN   0x66FFFF



/*
This file has for objective to 
*/

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

static void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int offset;

	offset = (y * img->line_length) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void init_c(t_complex *z, t_complex *c, t_fractal *fract)
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

static void	handle_pixel(int x, int y, t_fractal *fract)
{
	t_complex	z;
	t_complex	c;
	double		r_temp;
	double		i_temp;
	int			i;
	int			color;

	i = 0;
	z.r = (map(x, -2, 2, 0, WIDTH) * fract->zoom_factor) + fract->shift_x; // starting from the left
	z.i = (map(y, +2, -2, 0, HEIGHT) * fract->zoom_factor) + fract->shift_y; // starting from the top
	init_c(&z, &c, fract);
	while (i < fract->iterations_nbr)
	{
		r_temp = z.r;
		i_temp = z.i;
		z.r = (z.r * z.r) - (z.i * z.i) + c.r;
		z.i = (2 * r_temp * i_temp) + c.i;
		if (((z.r * z.r) + (z.i * z.i)) > fract->escape_radius) // using the modulus of z: |z| = cˆ2 = √(aˆ2 + bˆ2) if |z| > 2, assume point escaped because of the domain restrictions with c the escape radius 
		{
			color = map(i, BLACK, WHITE, 0, fract->iterations_nbr);
			my_pixel_put(x, y, &fract->image, color);
			return;
		}
		i++;
	}
	my_pixel_put(x, y, &fract->image, WHITE);
}

void	fractal_render(t_fractal *fract)
{
	int	x;
	int	y;

	x = 0; // de base = -1 et incrementation ++x
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
	mlx_put_image_to_window(fract->mlx_connection, fract->mlx_window, fract->image.image_ptr, 0, 0);
}