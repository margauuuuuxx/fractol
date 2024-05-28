/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:37:40 by marlonco          #+#    #+#             */
/*   Updated: 2024/05/09 14:09:50 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
uintptr_t is defined in <stdint.h>: 
	unsigned int type capable of holding a ptr.
	it's guaranteed to be large enough to store the value of a ptr
substracting 10 we obtain 0-5 then adding 'a' to convert to the adequate letter
*/

int	ft_len_ptr(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

void	ft_print_ptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_print_ptr(ptr / 16);
		ft_print_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (ptr == 0)
		count += write(1, "0", 1);
	else
	{
		ft_print_ptr(ptr);
		count += ft_len_ptr(ptr);
	}
	return (count);
}
