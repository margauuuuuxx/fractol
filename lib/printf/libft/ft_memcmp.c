/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:28:02 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/16 11:48:30 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;

	i = 0;
	if (n == 0)
		return (0);
	while (*(unsigned char *)(s1) == *(unsigned char *)(s2) && i < n - 1)
	{
		s1++;
		s2++;
		i++;
	}
	if (i < n)
		return (*(unsigned char *)(s1) - *(unsigned char *)(s2));
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "coucou";
	char	s2[] = "coca";
	size_t	n;

	n = 5;
	printf("%d\n", ft_memcmp(s1, s2, n));
	printf("True function: %d", memcmp(s1, s2, n));
	return (0);
}
*/