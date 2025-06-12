/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:36:17 by marlonco          #+#    #+#             */
/*   Updated: 2025/06/12 22:22:40 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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

double	atoi_dbl(char *str)
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
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			s *= -1;
	while (*str != '.' && *str != ',' && *str)
		integer_part = (integer_part * 10) + (*str++ - 48);
	if (*str == '.' || *str == ',')
		str++;
	while (*str)
	{
		pow /= 10;
		fractional_part = fractional_part + (*str - 48) * pow;
		str++;
	}
	return ((integer_part + fractional_part) * s);
}

int	check_number(char *str)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == '.' || str[i] == ',')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	exit_julia_error(void)
{
	ft_putstr_fd("Error: Julia parameters must be numbers\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
