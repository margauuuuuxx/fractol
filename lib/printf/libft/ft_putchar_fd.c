/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:48:33 by marlonco          #+#    #+#             */
/*   Updated: 2024/04/10 16:21:22 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, sizeof(char));
}
/*
int	main(void)
{
	int	fd;

	fd = open("filetest", O_WRONLY);
	if (fd == -1)
		exit (1);
	ft_putchar_fd('x', fd);
	return (0);
}
*/