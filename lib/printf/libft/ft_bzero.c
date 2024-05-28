/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:47:02 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/11 13:21:48 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	str[] = "coucou";
	char	str2[] = "coucou";

	ft_bzero(str, 4);
	bzero(str2, 4);
	printf("%s\n", str);
	printf("True function:%s", str2);
	return (0);
}
*/