/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:10:20 by marlonco          #+#    #+#             */
/*   Updated: 2024/05/09 14:11:37 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "../libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_hexa(int n, char c);
int	ft_putptr(unsigned long long ptr);
int	ft_printnbr(int n);
int	ft_unsigned(unsigned int n);
int	ft_putchar2(char c);
int	ft_putstr2(char *str);

#endif 