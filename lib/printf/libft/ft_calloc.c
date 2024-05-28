/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:20:19 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/12 13:54:13 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	array = malloc(count * size);
	if (array == NULL)
		return (NULL);
	ft_memset(array, 0, (count * size));
	return (array);
}
/*
int	main(void)
{
	int		x;
	char	*ptr;
	char	*ptr2;

	x = 3;
	ptr = ft_calloc(x, sizeof(char));
	ptr2 = calloc(x, sizeof(char));
	for (int i = 0; i < x; i++)
	{
		printf("%d\n", ptr[i]);
		printf("X%d\n", ptr2[i]);
	}
	return (0);
}
*/