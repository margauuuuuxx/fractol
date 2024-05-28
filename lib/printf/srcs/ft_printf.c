/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:09:31 by marlonco          #+#    #+#             */
/*   Updated: 2024/05/09 14:07:53 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_format(va_list args, char c)
{
	if (c == 'x' || c == 'X')
		return (ft_hexa(va_arg(args, int), c));
	else if (c == 'd' || c == 'i')
		return (ft_printnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	else if (c == 'c')
		return (ft_putchar2(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr2(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long long)));
	else if (!c)
		return (0);
	else
		return (ft_putchar2(c));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_format(args, str[i]);
		}
		else
			count += ft_putchar2(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// int main()
// {
// 	ft_printf("hello");
// }
