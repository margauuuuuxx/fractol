/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:14:26 by marlonco          #+#    #+#             */
/*   Updated: 2024/05/24 16:40:14 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

/*
This function has for objetive to render fractals for the Julia and Mandelbrot sets 
*/


/* 
parameters are passed in the COMMAND LINE to define what type of fractals will be displayed 
option to have more parameters for rendering options
if no parameters are entered --> display a list of available parameters and exit 
*/

// typical user input: type (mandelbrot/julia), max iterations, color options, window height, window length

int type(char *type)
{
    if (type == "julia" || type == "Julia")
        return (ft_printf("Please enter your starting z value"), 1);
    else if (type == "mandelbort" || type == "Mandelbrot")
        return (1);
    else 
        return (printf("Invalid fractal type, please select one of those two: Julia/Mandelbrot"), NULL);
}

int ft_check(int argc, char **argv)
{
    if (argc != 6)
    {
        if (argc < 6)
            return (ft_printf("Not enough arguments submitted. Here are the needed parameters:"), NULL); // COMPLETE
        else if (argc > 6)
            return (ft_printf("Too much arguments submitted.", NULL));
    }
    int_type_check(argv[1]);
    else if (!ft_atoi(argv[2]) || !(ft_atoi(argv[4])) || !(ft_atoi(argv[5])))
        return (NULL);
    // COLOR ?
}

int main(int argc, char **argv)
{
    char    *type;
    int     max_iterations;
    char    *color_option;
    int     x;
    int     y;

    ft_check(int argc, char **argv);

    type = argv[1];
    max_iterations = ft_atoi(argv[2]);
    color_option = argv[3];
    x = ft_atoi(argv[4]);
    y = ft_atoi(argv[5]);
    
    ft_rendering(x, y, max_iterations, type);
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