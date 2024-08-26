/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:36:17 by marlonco          #+#    #+#             */
/*   Updated: 2024/08/26 15:57:07 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// double	generate_random_c(void)
// {
// 	return(((double)rand() / RAND_MAX) * 3.0 - 1.5);
// }

// void	set_random_julia(double *cx, double *cy)
// {
// 	*cx = generate_random_c();
// 	*cy = generate_random_c();
// }

// linear interpolation
double	map(double unscaled_nbr, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled_nbr - old_min) / (old_max - old_min) + new_min;	
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0 || s == NULL)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// int	ft_isdigit(int c)
// {
// 	if (c >= 48 && c <= 57)
// 		return (1);
// 	else
// 		return (0);
// }

double atoi_dbl(char *str)
{
	long	integer_part;
	double	fractional_part;
	int		s;
	double	pow;

	integer_part = 0;
	fractional_part = 0;
	s = 1;
	pow = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			s *= -1;
	while (*str != '.' && *str)
		integer_part = (integer_part * 10) + (*str++ - 48);
	if (*str == '.')
		++s;
	while (*str)
	{
		pow /= 10;
		fractional_part = fractional_part + (*str++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * s);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;
	
	result.r = z1.i + z2.i;
	result.i = z1.i + z2.i;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.r = (z.r * z.r) - (z.i * z.i);
	result.i = 2 * z.r * z.i;
	return (result);
}