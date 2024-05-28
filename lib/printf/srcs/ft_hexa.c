/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:06:57 by marlonco          #+#    #+#             */
/*   Updated: 2024/05/09 14:07:24 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/*
a is implicitely taken as a binary number for the bitwise AND operation
and the right shift operator (>>)
This operation (>>) is equivalent to int /16 it's used to process the next nibble
j = i - 1 to skip the \0
*/

static int	ft_conversion(int a, char *base)
{
	char	tab[9];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (a == 0)
		return (write(1, "0", 1));
	while (a != 0 && i < 8)
	{
		tab[i] = base[a & 0xf];
		a = a >> 4;
		i++;
	}
	tab[i] = '\0';
	j = i - 1;
	while (j >= 0)
	{
		if (write(1, &tab[j], 1) == -1)
			return (-1);
		j--;
	}
	return (i);
}

int	ft_hexa(int n, char c)
{
	if (c == 'x')
		return (ft_conversion(n, "0123456789abcdef"));
	if (c == 'X')
		return (ft_conversion(n, "0123456789ABCDEF"));
	else
		return (0);
}

// #include <stdio.h>
// int main()
// {
//     int n = -200000;
// 	char	c = 'x';
//     ft_hexa(n, c);
//     printf("\nTrue function: %x", n);
// }
