/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:05:20 by marlonco          #+#    #+#             */
/*   Updated: 2024/05/24 13:32:01 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This file has for objective to plot the points for a mandelbrot or julia set.
Let c be the constant complex number, decomposed in its real and imaginary parts.
Let z be the complex number used for iterating.
Let x and y be the dimensions of the display window.
*/

#include "../include/fractol.h"

void    ft_JM(int x, int y, int max_iterations, char *type)
{
    int         count;
    int         i;
    int         j;
    t_complex   z;
    t_complex   c;
    double      tempx;

    count = 0;
    i = 0;

    if (type == "Mandelbort" || type == "mandelbrot")
    {
        z.real = 0;
        z.imaginary = 0;
    }
    
    // WHAT IN THE CASE OF A JULIA ?
    
    // scanning each point in the window 
    while (i < x)
    {
        j = 0;
        while (j < y)
        {
            while ((pow(z.real, 2) + pow(z.imaginary)) < 4 && count < max_iterations) // |z| < 2 --> √(zxˆ2 + zyˆ2)
            {
                tempx = pow(z.real, 2) - pow(z.imaginary, 2) + c.real;
                z.imaginary = 2 * z.real * z.imaginary + c.imaginary;
                z.real = tempx;
                count += 1;
            }
            ft_put_pixel(&image, x, y, color); // COLOR
            j++;
        }
        i++;
    }
}