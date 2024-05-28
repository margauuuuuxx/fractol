/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:03:13 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/16 15:34:29 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*str;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	str = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		*(unsigned char *)str = *(unsigned char *)src;
		i++;
		str++;
		src++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "coucou";
	char	dest[] = "11";
	size_t	n;

	//char    dest2[] = "hhjhbjhbjbh";
	n = 8;
	printf("%s\n", ft_memcpy(dest, src, n));
	printf("True function: %s", memcpy(dest, src, n));
	return (0);
}
*/