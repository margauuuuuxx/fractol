/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:14:26 by marlonco          #+#    #+#             */
/*   Updated: 2024/06/20 13:10:42 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <math.h>
# include "../lib/libft/libft.h"

/*
This function has for objetive to render fractals for the Julia and Mandelbrot sets 
*/


/* 
parameters are passed in the COMMAND LINE to define what type of fractals will be displayed 
option to have more parameters for rendering options
if no parameters are entered --> display a list of available parameters and exit 
*/

// typical user input: type (mandelbrot/julia), z value, max iterations, color options, 

// int type_check(char *type)
// {
//     if (type == "J")
//         return (ft_printf("Please enter your starting z value"), 1);
//     else if (type == "M")
//         return (1);
//     else 
//         return (printf("Invalid fractal type, please select one of those two: J (Julia)/ M (Mandelbrot)"), NULL);
// }

// int ft_check(int argc, char **argv)
// {
// 	if (argc < 2)
// 		return (ft_printf("Not enough arguments submitted, please select a fractal type (J/M).", 0));
//     else if (argv[1] == "J" && argc != 3)
// 		return (ft_printf("Not enough arguments provided for a Julia, please provide the integer starting z value.", 0));
//     else if (argc > 5) // ADAPT THE # OF ARGS ACCORDINGLY 
//         return (ft_printf("Too much arguments submitted.", 0));
//     else if (!(type_check(argv[1])))
// 		return (0);
//     else if (!ft_atoi(argv[2]) || !(ft_atoi(argv[4])) || !(ft_atoi(argv[5])))
//         return (0);
// 	else 
// 		return (1);
//     // COLOR ?
// }

// int main(int argc, char **argv)
// {
//     char    *type;
//     int     max_iterations;
//     char    *color_option;
//     int     x;
//     int     y;

//     ft_check(argc, **argv);

//     type = argv[1];
//     max_iterations = ft_atoi(argv[2]);
//     color_option = argv[3];
//     x = ft_atoi(argv[4]);
//     y = ft_atoi(argv[5]);
    
//     ft_rendering(x, y, max_iterations, type);
// }

int		name_validity(char *name, t_fractal *fractal)
{
	if (ft_strncmp((const char *)name, "mandelbrot", 11) == 0)
	{
		fractal->fractal_type = 1;
		return (1);
	}
	else if (ft_strncmp((const char *)name, "julia", 7) == 0)
	{
		fractal->fractal_type = 2;
		return (2);
	}
	else
		return (0);
}

int	ft_draw_fractal(t_fractal *fractal, int type)
{
	if (type == 1)
		ft_draw_mandelbrot(fractal);
	else if (type == 2)
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
	fractal->offset_x = -1.21;
	fractal->max_iterations = 42;
}

void	mlx_initialization(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, WIDTH, "Fractol");
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, WIDTH);
	fractal->address = mlx_get_data_addr(fractal->image, &fractal->bpp, 
										&fractal->line_length, &fractal->endian);
}

int main(int argc, char **argv)
{
	t_fractal	*fractal;
	
	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!(fractal))
		return (-1);
	if (name_validity(argv[1], fractal) == 0 || argc != 2)
	{
		ft_printf("Please select a valid fractal type: mandelbrot / julia");
		return (0);
	}
	mlx_initialization(fractal);
		if (argc == 2)
	fractal_initialization(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal); // 17 = close window | 0L = no mask needed: window close is straightforward with no subtypes
	fractal->fractal_type = name_validity(argv[1], fractal);
	ft_draw_fractal(fractal, fractal->fractal_type);
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