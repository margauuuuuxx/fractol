/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:55:15 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/11 13:51:49 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/*
void	ft_test(unsigned int i, char *str)
{
	str[i] -= 32;
}

int	main(void)
{
	char	str[] = "coucou";

	ft_striteri(str, ft_test);
	printf("%s", str);
	return (0);
}
*/