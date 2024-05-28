/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:13:31 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/12 17:10:05 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	size_t				i;

	str = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	int		s[] = {1, 2, 3};
	int		c;
	char	s2[] = "coucou";
	int		c2;
	size_t	n;

	c = '1';
	c2 = 'c';
	n = 3;
	printf("%d\n", (int)ft_memchr(s, c, n));
	printf("True function: %d\n", (int)memchr(s, c, n));
	printf("%s\n", (char *)ft_memchr(s2, c2, n));
	printf("True function: %s", (char *)memchr(s2, c2, n));
	return (0);
}
*/