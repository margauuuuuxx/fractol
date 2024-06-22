/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:47:31 by marlonco          #+#    #+#             */
/*   Updated: 2024/06/21 20:10:13 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
This file has for objective to 
*/

void	*ft_render_thread(void *args)
{
	t_thread	*t;
	int			x;
	int			y;

	t = (t_thread *)args; // c'etait deja un t_thread mais on typecast pcq dans la def de pthread_create les args sont des (void *)
	y = HEIGHT / THREADS * t->id; // ??
	while (y < HEIGHT / THREADS * (t->id + 1)) // why + 1 ?
	{
		x = 0;
		while (x < WIDTH)
		{
			*(t->mlx->data + y * WIDTH + x) = t->mlx->fractal.pixel(x, y, &t->mlx->viewport, t->mlx); // ??
			x++;
		}
		y++;
	} 
	return (NULL);
}

void	ft_draw(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_set_pixel(mlx->image, x, y, ft_get_color(*(mlx->data + y * WIDTH + x), mlx));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}

void	ft_render(t_mlx *mlx)
{
	int			i;
	t_render	*r;

	i = 0;
	r = &mlx->render; // en gros je dis aue l'adresse de ce qui se trouve a mlx.render = r donc les deux sont =
	while (i < THREADS)
	{
		r->args[i].id = i;
		r->args[i].mlx = mlx;
		pthread_create(r->threads + i, NULL, ft_render_thread, &(r->args[i])); // r.thread == pthread mis pq + i
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(r->threads[i], NULL);
		i++;
	}
	ft_draw(mlx);
}