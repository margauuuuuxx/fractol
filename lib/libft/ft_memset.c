/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:58:55 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/11 13:18:58 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*str;

	str = s;
	while (n > 0)
	{
		*(unsigned char *)str = (unsigned char)c;
		str++;
		n--;
	}
	return (s);
}
/*
int	main(void)
{
	char	str[] = "coucou";
	char	str2[] = "coucou";
	size_t	n;
	int		c;

	n = 4;
	c = 'x';
	ft_memset(str, c, n);
	printf("%s\n", str);
	memset(str2, c, n);
	printf("True function: %s", str2);
	return (0);
}
*/