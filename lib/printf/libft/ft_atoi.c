/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:12:16 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/16 17:33:49 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_skip(const char **str, int *s)
{
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*s *= -1;
		(*str)++;
	}
}

int	ft_atoi(const char *str)
{
	int		s;
	long	num;
	long	overflow;

	s = 1;
	num = 0;
	overflow = 0;
	ft_skip(&str, &s);
	while (ft_isdigit(*str))
	{
		num *= 10;
		num += (*str - 48);
		str++;
		if (overflow > num && s == 1)
			return (-1);
		else if (overflow > num && s == -1)
			return (0);
		overflow = num;
	}
	return ((int)num * s);
}
/*
int	main()
{
	printf("%d\n", ft_atoi(((void *)0)));
	printf("True function: %d", atoi(((void *)0)));
	return (0);
}
// LLONG MIN = −9223372036854775808
// LLONG MAX = 9223372036854775807
// UNSIGNED LONG = 18446744073709551615
*/