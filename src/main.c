/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:14:26 by marlonco          #+#    #+#             */
/*   Updated: 2025/06/12 22:23:04 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" \
or \n\t\"./fractol julia <value_1> <value_2>\" or \
\n\t\"./fractol burning\"\n"

int	main(int argc, char **argv)
{
	t_fractal	fract;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0) 
		|| (argc == 2 && ft_strncmp(argv[1], "burning", 7) == 0)
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0))
	{
		fract.name = argv[1];
		if (ft_strncmp(fract.name, "julia", 5) == 0)
		{
			if (!check_number(argv[2]) || !check_number(argv[3]))
				exit_julia_error();
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
