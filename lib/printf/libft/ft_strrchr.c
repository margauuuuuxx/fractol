/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:16:01 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/10 16:24:41 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	l;

	l = ft_strlen(s);
	while (s && l >= 0)
	{
		if (s[l] == (char)c)
			return ((char *)&s[l]);
		l--;
	}
	return (0);
}
/*
int	main(void)
{
	char	str[] = "coucou";
	int		c;

	c = 9;
	printf("%s\n", ft_strrchr(str, c));
	printf("True function: %s", strrchr(str, c));
	return (0);
}
*/