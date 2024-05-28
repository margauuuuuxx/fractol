/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:15:35 by marlonco          #+#    #+#             */
/*   Updated: 2024/05/09 11:37:36 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar2(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr2(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_putstr2("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_int_len(long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	else if (n == 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_printnbr(int n)
{
	int	len;

	len = ft_int_len(n);
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar2('-');
		n *= -1;
		ft_printnbr(n);
	}
	else if (n <= 9)
		ft_putchar2(n + 48);
	else
	{
		ft_printnbr(n / 10);
		ft_printnbr(n % 10);
	}
	return (len);
}

// #include <stdio.h>
// int main()
// {
// 	int n = -10;
// 	printf("%d\n", ft_int_len(n));
// 	ft_printnbr(n);
// 	printf("\n%d", n);
// 	return (0);
// }
