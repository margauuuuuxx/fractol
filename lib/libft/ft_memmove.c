/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:27:08 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/16 15:35:26 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// overlapping = when two blocks of memory share some of the same memory space
// no overlap --> fdest begins before fsrc 
// fdest and fsrc refers to the memory addresses

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;

	i = 0;
	if (dest == src || n == 0)
		return (dest);
	if (dest > src && (const unsigned char *)(dest)
			< ((const unsigned char *)(src) + n))
	{
		while (n--)
			((unsigned char *)(dest))[n] = ((unsigned char *)(src))[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)(dest))[i] = ((unsigned char *)(src))[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[] = "coucou";
	char	src[] = "hellooooo";
	size_t	n;

	n = 8;
	ft_memmove(dest, src, n);
	printf("%s\n", dest);
	memmove(dest, src, n);
	printf("True function: %s", dest);
	return (0);
}
*/