/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:32:46 by marlonco          #+#    #+#             */
/*   Updated: 2024/06/24 09:49:47 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_pixel	ft_julia(int x, int y, t_viewport *v, t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int		i;

	(void)mlx;
	i = 0;
	z = ft_complex_conversion(x, y, v);
	c = v->mouse;
	while (pow(z.r, 2) + pow(z.i, 2) < 256 && i < v->max) // 256 is treshold for stopping iterations
	{
		temp.r = pow(z.r, 2) - pow(z.i, 2) + c.r;
		temp.i = 2 * z.i * z.r + c.i;
		if (z.r == temp.r && z.i == temp.i)
		{
			i = v->max; 
			break;
		}
		z.r = temp.r;
		z.i = temp.i;
		i++;
	}
	return (t_pixel){.c = z, .i = i};
}

void	ft_julia_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
}