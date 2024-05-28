/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:09:17 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/16 17:37:39 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	else if (n == 0)
		len = 1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	a;

	a = n;
	len = ft_len(a);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (a < 0)
	{
		str[0] = '-';
		a *= -1;
	}
	if (a == 0)
		str[0] = '0';
	while (a > 0)
	{
		len--;
		str[len] = '0' + (a % 10);
		a /= 10;
	}
	return (str);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(0));
	return (0);
}
*/