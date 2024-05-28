/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:50:45 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/11 12:49:11 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	min;
	size_t	max;
	size_t	len;

	min = 0;
	max = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	while (s[min] && ft_char_check(s[min], set) == 1)
		min++;
	while (min < max && ft_char_check(s[max - 1], set) == 1)
		max--;
	len = max - min;
	return (ft_substr(s, min, len));
}
/*
int	main(void)
{
	printf("%s", ft_strtrim("cc", "c"));
	return (0);
}
*/