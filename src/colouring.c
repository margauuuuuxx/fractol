/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colouring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:07:27 by marlonco          #+#    #+#             */
/*   Updated: 2024/06/24 12:01:47 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return;
	*(int *)(image->ptr + ((x + y * WIDTH) * image->bpp)) = color;
}

t_color	ft_linear(double i, int max, t_palette *p)
{
	double	j;
	double	adjust;
	int		k;

	if (p->cycle)
		j = fmod(i, p->cycle - 1) / (p->cycle -1);
	else
		j = i / max;
	k = p->count - 1;
	adjust = fmod(j, 1.0f / k) * k;
	return
}

t_color	ft_smooth(t_pixel p, int max, t_palette *pal)
{
	double	i;
	double	z;
	double	n;

	z = log(pow(p.c.r, 2) + pow(p.c.i, 2)) / 2.0f;
	n = log(z / log(2)) / log(2);
	i = p.i + i - n;
	if (i < 0)
		i = 0;
	return(ft_linear(i, max, pal));
}

int	ft_get_color(t_pixel p, t_mlx *mlx)
{
	if (p.i >= mlx->viewport->max)
		return (0x000000);
	if (mlx->smooth)
		return(ft_smooth(p, mlx->viewport->max, mlx->color).value);
	return (ft_linear((double)p.i, mlx->viewport->max, mlx->color).value);
}

t_color_RGB	ft_color_init(void)
{
	t_color_RGB	color;

	color.r = 0;
	color.g	= 0;
	color.b	= 0;
	return (color);
}

t_color   ft_hsv_to_rgb(t_color c1, t_color c2, t_color c3)
{
    double  r;
    double  g;
    double  b;
    double  f;
    double  p;
    double  q;
    double  t;
    int     i;
    t_RGB   color;

    i = (int)(h / 60.0) % 6; // divide by 60 to find the segment and takes the int part
    f = h / 60.0 - i;
    p = v * (1 - s);
    q = v * (1 - f * s);
    t = v * (1 - (1 - f) * s);

    switch (i)
    {
        case 0: r = v, g = t, b = p; break; // red
        case 1: r = q, g = v, b = p; break; // yellow
        case 2: r = p, g = v, b = t; break; // green
        case 3: r = p, g = q, b = v; break; // cyan
        case 4: r = t, g = p, b = v; break; //blue
        case 5: r = v, g = p, b = q; break; // magenta 
    }

    color.r = (int)(r * 255);
    color.g = (int)(g * 255);
    color.b = (int)(b * 255);
    return (color);
}


void    ft_colouring(double log_iterations, int max_iterations)
{
    double  t;
    double  h;
    double  s;
    double  v;
    t_RGB   color;

    t = (double)log_iterations / max_iterations; // 0 = the pt escapes immediately, 1 = the pt takes the max it to escape
    h = 360 * t;
    s = 1.0; // full saturation for vibrant colors
    v = 1.0; // full brightness

    color = ft_hsv_to_rgb(h, s, v);
}

double  ft_log(int iterations, double modulus) // max_iterations was initially as parameter
{
    double  log_modulus;
    double  log_iterations;

    log_modulus = log(modulus);
    log_iterations = iterations + 1 - log(log_modulus);
    return (log_iterations);
}
