/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:05:20 by marlonco          #+#    #+#             */
/*   Updated: 2024/05/24 16:38:08 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This file has for objective to plot the points for a mandelbrot set.
Let c be the constant complex number, decomposed in its real and imaginary parts.
Let z be the complex number used for iterating, starting at 0.
Let x and y be the dimensions of the display window.
*/

#include "../include/fractol.h"

void	ft_put_pixel(t_data *data, int x, int y, t_RGB color)
{
	char	        *dest;
    unsigned int    color_int;

    color_int = (color.r << 16) | (color.g << 8) | color.b; //then the int is in format 0xRRGGBB
	dest = data->address + (y * data->line_length + x * (data->bpp / 8)); // for the row & column offset
	*(unsigned int*)dest = color_int;
}

void    ft_JM(int x, int y, int max_iterations, char *type)
{
    int         count;
    int         i;
    int         j;
    t_complex   z;
    t_complex   c;
    double      tempx;
    double      modulus;
    t_RGB       color;

    count = 0;
    i = 0;

    if (type == "Mandelbort" || type == "mandelbrot")
        z = {0.0, 0.0};
    else 
    // WHAT IN THE CASE OF A JULIA ?
    
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
            if (count < max_iterations)
            {
                modulus = sqrt(pow(z.real, 2) + pow(z.imaginary));
                color = ft_colouring(ft_log(count, modulus), max_iterations);
            }
            else
                color = {0, 0, 0};
            ft_put_pixel(&image, x, y, color);
            j++;
        }
        i++;
    }
}

void    ft_rendering(int x, int y, int max_iterations, char *type)
{
    void    *mlx;
    void    *window;
    t_data  image;
    int     i;
    int     j;
    
    mlx = mlx_init();
    image.image = mlx_new_image(mlx, x, y); // RESTRICTION ON X AND Y VALUES 
    image.address = mlx_get_data_addr(image.image, &image.bpp, &image.line_length, &image.address);
    window = mlx_new_window(mlx, x, y, "FRACTOL");
    ft_JM(x, y, max_iterations, type);
    mlx_put_image_to_window(mlx, window, image.image, 0, 0);
    mlx_loop(mlx);
}