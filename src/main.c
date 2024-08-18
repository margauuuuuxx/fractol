/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:14:26 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/18 11:29:36 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

/*
This function has for objetive to render fractals for the Julia and Mandelbrot sets  
parameters are passed in the COMMAND LINE to define what type of fractals will be displayed 
option to have more parameters for rendering options
if no parameters are entered --> display a list of available parameters and exit 
*/

int	ft_name_check(char *name)
{
	if ((ft_strncmp((const char *)name, "mandelbrot", 11) == 0)
			|| (ft_strncmp((const char *)name, "julia", 6) == 0))
		return (1);
	else
		return (0);
}

int	ft_die(char *reason)
{
	ft_printf(reason);
	return (1);
}

int	hook_expose(t_mlx *mlx)
{
	ft_render(mlx);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	t_fractal	*fractal;
// 	t_mlx		*mlx;
	
// 	fractal = malloc(sizeof(t_fractal));
// 	if (fractal == NULL)
// 		return (1);
// 	if (argc != 2)
// 		return (ft_die("Too much or not enough arguments."));
// 	if (ft_name_check(argv[1]) == 1)
// 		fractal->name = argv[1];
// 	else 
// 		return(ft_die("Please type in a valid fractal name: julia  mandelbrot"));
// 	if ((mlx = ft_mlx_init(fractal)) == NULL)
// 		return(ft_die("MLX couldn't initialize properly."));
// 	ft_viewport_init(mlx);
// 	mlx_key_hook(mlx->window, key_hook, mlx);
// 	mlx_expose_hook(mlx->window, hook_expose, mlx); // what is this fct ?
// 	mlx_hook(mlx->window, SCROLL_UP, 1L << 2, hook_mousemovement, mlx);
// 	mlx_hook(mlx->window, SCROLL_DOWN, 1L << 3, hook_mouseend, mlx);
// 	mlx_hook(mlx->window, MOUSE_CURSOR, 1L << 6, hook_mousecursor, mlx);
// 	mlx_hook(mlx->window, 17, 0L, exit_fractal, mlx); // 17 = close window | 0L = no mask needed: window close is straightforward with no subtypes
// 	mlx_loop(mlx->mlx);
// 	return (0);
// }

int main(int argc, char **argv)
{
	t_fractal	fract;
	
	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
			|| (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0))
	{
		fract.name = argv[1];
		fractal_init(&fract);
		fractal_render(&fract);
		mlx_loop(fract.mlx_connection);
	}
	else
	{
		ft_printf("%s", ERROR_MESSAGE);
		exit(EXIT_FAILURE);
	}
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