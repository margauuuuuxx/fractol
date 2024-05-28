/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:23:43 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/12 14:03:15 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	fdest;
	size_t	fsrc;

	i = 0;
	j = ft_strlen(dest);
	fsrc = ft_strlen(src);
	fdest = ft_strlen(dest);
	if (fdest < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && fdest + i < dstsize - 1)
		{
			dest[j] = src[i];
			i++;
			j++;
		}
		dest[j] = '\0';
	}
	if (fdest >= dstsize)
		fdest = dstsize;
	return (fdest + fsrc);
}
/*
int	main(void)
{
	char	dest[] = "helloooo";
	char	dest2[] = "hellooooo";
	char	src[] = "worldddd";
	size_t	n;

	n = 7;
	printf("%zu\n", ft_strlcat(dest, src, n));
	printf("%s\n", dest);
	printf("True function: %lu\n", strlcat(dest2, src, n));
	printf("%s", dest2);
	return (0);
}
*/