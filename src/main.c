/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:14:26 by marlonco          #+#    #+#             */
/*   Updated: 2024/06/20 15:50:34 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <math.h>
# include "../lib/libft/libft.h"
#include <stdio.h>

/*
This function has for objetive to render fractals for the Julia and Mandelbrot sets  
parameters are passed in the COMMAND LINE to define what type of fractals will be displayed 
option to have more parameters for rendering options
if no parameters are entered --> display a list of available parameters and exit 
*/

int	ft_draw_fractal(t_fractal *fractal, char *type)
{
	if ((ft_strncmp((const char *)type, "mandelbrot", 11) == 0))
		ft_draw_mandelbrot(fractal);
	else if (ft_strncmp((const char *)type, "julia", 6) == 0)
	{
		if (!fractal->cx && !fractal->cy)
		{
			fractal->cx = -0.745429;
			fractal->cy = -0.05;
		}
		ft_draw_julia(fractal);
	}
	else
	{
		ft_printf("Please select a valid fractal type: mandelbrot / julia");
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
	return (0);
}

void	fractal_initialization(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFCBE11;
	fractal->offset_x = -1.21;
	fractal->offset_y = -1.21;
	fractal->max_iterations = 42;
}

void	mlx_initialization(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, SIZE, "Fractol");
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, SIZE);
	fractal->address = mlx_get_data_addr(fractal->image, &fractal->bpp, 
										&fractal->line_length, &fractal->endian);
}

int main(int argc, char **argv)
{
	t_fractal	*fractal;
	
	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!(fractal))
		return (-1);
	if (argc != 2)
	{
		ft_printf("Please enter a valid fractal type: mandelbrot / julia");
		return (0);
	}
	mlx_initialization(fractal);
	fractal_initialization(fractal);
	//fractal_type(argv[1], fractal);
	printf("zoom : %f", fractal->zoom);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal); // 17 = close window | 0L = no mask needed: window close is straightforward with no subtypes
	ft_draw_fractal(fractal, argv[1]);
	
	mlx_loop(fractal->mlx);
	return (0);
}

    
    // log_escape_radius = log(escape_radius);

    // // coulouring
    // if (iterations < max_iterations)
    //     ft_log(iterations, max_iterations, modulus);
    // else
        // colour = black
    // modulus = 0;
    // while (i < max_iterations)
    // {
    //     // |z| < escape radius ? --> magnitude of z = √(aˆ2 + bˆ2) with z = a + bi
    //     modulus = sqrt(pow(z.real) + pow(z.imaginary));
    //     if (modulus < escape_radius)
    //         // colour of the pixel = black
    //     else
    //         // color depends on the number of iterations needed to go to infinity 
    // }