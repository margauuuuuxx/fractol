/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:23:20 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/16 15:36:44 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (dstsize == 0)
		return (j);
	while (i < dstsize - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return ((size_t)j);
}
/*
int	main(void)
{
	char	src[] = "coucou";
	char	dest[20] = "";
	char	dest1[20] = "";
	size_t	s;

	s = 0;
	printf("%zu\n", ft_strlcpy(dest, src, s));
	printf("%s\n", dest);
	printf("True function: %lu\n", strlcpy(dest1, src, s));
	printf("%s\n", dest1);
	return (0);
}
*/