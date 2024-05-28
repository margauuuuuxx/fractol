/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:34:49 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/16 17:52:03 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
			j++;
		if (j == ft_strlen(needle))
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	//char	s1[] = "coucou c'est moi";
	//char	s2[] = "coux";
	//size_t	n;

	//n = 5;
	printf("%s\n", ft_strnstr("fake", ((void *)0), 3));
	printf("True function: %s", strnstr("fake", ((void *)0), 3));
	return (0);
}
*/