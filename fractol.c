/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:14:26 by marlonco          #+#    #+#             */
/*   Updated: 2024/05/18 14:04:19 by marlonco         ###   ########.fr       */
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

void    ft_fractal(int argc, char **argv)
{
    int i;
    int max_iterations; // define an int or something else ?
    t_complex z;
    double escape_radius;
    double log_escape_radius;
    int iterations;

    i = 0;
    max_iterations = 0;
    z = {0.0, 0.0};
    escape_radius = 0;
    log_escape_radius = log(escape_radius);
    iterations = 0;
    
    // create a grid of complex numbers 

    // iterating to check for escapes 
    double  modulus;

    modulus = 0;
    while (i < max_iterations)
    {
        // |z| < escape radius ? --> magnitude of z = √(aˆ2 + bˆ2) with z = a + bi
        modulus = sqrt(pow(z.real) + pow(z.imaginary));
        if (modulus < escape_radius)
            // colour of the pixel = black
        else
            // color depends on the number of iterations needed to go to infinity 
    }

    // coulouring
    if (iterations < max_iterations)
        ft_log(iterations, max_iterations, modulus);
    else
        // colour = black
}
