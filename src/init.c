/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:24:33 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/18 14:01:20 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
Key objectives:
	1) Initialize mlx ;
	2) Listening events ;
	3) Hooks data
*/

// t_image	*ft_del_image(t_mlx *mlx, t_image *image)
// {
// 	if (image != NULL)
// 	{
// 		if (image->image != NULL)
// 			mlx_destroy_image(mlx->mlx, image->image);
// 		// memdel
// 	}
// 	return (NULL);	
// }

// t_mlx	*ft_deletemlx(t_mlx *mlx)
// {
// 	if (mlx->window != NULL)
// 		mlx_destroy_window(mlx->mlx, mlx->window);
// 	if (mlx->image != NULL)
// 		ft_del_image(mlx, mlx->image);
// 	// memdel 
// 	return (NULL);	
// }

static void	malloc_error(void)
{
	perror("Malloc error\n");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fract)
{
	fract->escape_radius = 4; // 2ˆ2 (useful for rendering)
	fract->iterations_nbr = 100;
}

static void	events_init(t_fractal *fract)
{
	// listening to the keys: KeyPress & KeyPressMask
	mlx_hook(fract->mlx_window, ON_KEYDOWN, 0, key_handler, fract);
	// listening to the mouse: ButtonPress & ButtonPressMask 
	mlx_hook(fract->mlx_window, ON_MOUSEUP, 0, mouse_handler, fract);
	// clicking to close the window: DestroyNotify & StructureNotifyMask
	mlx_hook(fract->mlx_window, ON_DESTROY, 0, close_handler, fract);
}

void	fractal_init(t_fractal *fract)
{
	fract->mlx_connection = mlx_init();
	if (fract->mlx_connection == NULL)
		malloc_error();
	fract->mlx_window = mlx_new_window(fract->mlx_connection, WIDTH, HEIGHT, fract->name);
	if (fract->mlx_window == NULL)
	{
		mlx_destroy_display(fract->mlx_connection);
		free(fract->mlx_connection);
		malloc_error();
	}
	fract->image.image_ptr = mlx_new_image(fract->mlx_connection, WIDTH, HEIGHT);
	if (fract->image.image_ptr == NULL)
	{
		mlx_destroy_window(fract->mlx_connection, fract->mlx_window);
		mlx_destroy_display(fract->mlx_connection);
		free(fract->mlx_connection);
		malloc_error();
	}
	fract->image.pixels_ptr = mlx_get_data_addr(fract->image.image_ptr, &fract->image.bpp, 
													&fract->image.line_length, &fract->image.endian);
	events_init(fract);
	data_init(fract);
}