/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:14:26 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/29 14:49:54 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" \
or \n\t\"./fractol julia <value_1> <value_2>\"\n"

int	main(int argc, char **argv)
{
	t_fractal	fract;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0) || (argc == 4
			&& ft_strncmp(argv[1], "julia", 5) == 0))
	{
		fract.name = argv[1];
		if (ft_strncmp(fract.name, "julia", 5) == 0)
		{
			fract.julia_r = atoi_dbl(argv[2]);
			fract.julia_i = atoi_dbl(argv[3]);
		}
		fractal_init(&fract);
		fractal_render(&fract);
		mlx_loop(fract.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
