/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:48:29 by marlonco          #+#    #+#             */
/*   Updated: 2024/05/22 14:02:35 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"
#include <mlx.h>

// put a pixel
void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dest;

	// for the offset
	dest = data->address + (y * data->line_length + x * (data->bpp / 8)); // ???
	*(unsigned int*)dest = color;
}

// creating a window
int	one_pixel()
{
	void	*mlx;
	void	*window;
	t_data	image;

	mlx = mlx_init(); // initializing mlx
	image.image = mlx_new_image(mlx, 1920, 1080); // initializing an image
	image.address = mlx_get_data_addr(image.image, &image.bpp, &image.line_length, &image.endian);
	window = mlx_new_window(mlx, 1920, 1080, "TEST");
	ft_put_pixel(&image, 1000, 500, 0x00FF0000);
	mlx_put_image_to_window(mlx, window, image.image, 0, 0);
	mlx_loop(mlx);
	return (0);
}

int main()
{
	void	*mlx;
	void	*window;
	t_data	image;
	int	i	= 0;
	int	j;

	mlx = mlx_init();
	image.image = mlx_new_image(mlx, 1920, 1080);
	image.address = mlx_get_data_addr(image.image, &image.bpp, &image.line_length, &image.endian);
	window = mlx_new_window(mlx, 1920, 1080, "TEST2");
	
	while (i < 1080)
	{
		j = 0;
		while (j < 1080)
		{
			ft_put_pixel(&image, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, window, image.image, 0, 0);
	mlx_loop(mlx);
	return (0);
}

