/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:24:33 by marlonco          #+#    #+#             */
/*   Updated: 2024/06/22 15:26:19 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
This file has for objective to initialize our mlx. 
t-mlx itself being constituted of multiple structs, from whom t_image, t_mouse, t_fractal and t_palette
*/

t_image	*ft_del_image(t_mlx *mlx, t_image *image)
{
	if (image != NULL)
	{
		if (image->image != NULL)
			mlx_destroy_image(mlx->mlx, image->image);
		// memdel
	}
	return (NULL);	
}

t_image	*ft_new_image(t_mlx *mlx)
{
	t_image	*image;
	if ((image = malloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((image->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT)) == NULL)
		return (ft_del_image(mlx, image));
	image->ptr = mlx_get_data_addr(image->image, &image->bpp, &image->line_length, &image->endian);
	image->bpp = 8; // ???
	return (image);
}

t_mlx	*ft_deletemlx(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->image != NULL)
		ft_del_image(mlx, mlx->image);
	// memdel 
	return (NULL);	
}

t_mlx	*ft_mlx_init(t_fractal *fractal)
{
	t_mlx	*mlx;
	char	*title;
	
	if ((mlx = malloc(sizeof(t_mlx))) == NULL) 
		return (NULL);
	title = ft_strjoin("Fractol - ", fractal->name);
	if ((mlx->mlx = mlx_init()) == NULL 
			|| (mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, title)) == NULL
			|| (mlx->image = ft_new_image(mlx)) == NULL
			|| (mlx->data = malloc(sizeof(t_pixel) * HEIGHT * WIDTH)) == NULL)
		return (ft_deletemlx(mlx));
	mlx->mouse.isdown = 0; // ??
	mlx->fractal = fractal;
	mlx->mouselock = 1 - fractal->mouse; // ??
	mlx->color = ft_color_init(); // SEE HOW I WANT TO COLOR 
	mlx->smooth = 1; // 
	return (mlx);
}