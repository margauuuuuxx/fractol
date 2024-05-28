/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:55:26 by marlonco          #+#    #+#             */
/*   Updated: 2024/05/07 15:12:02 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_len(long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*num;

	len = ft_len(n);
	num = malloc((len + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n > 0)
	{
		len--;
		num[len] = '0' + (n % 10);
		n /= 10;
	}
	return (num);
}

int	ft_unsigned(unsigned int n)
{
	int		count;
	char	*num;

	count = 0;
	if (n == 0)
		count += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		count += ft_putstr2(num);
		free (num);
	}
	return (count);
}
