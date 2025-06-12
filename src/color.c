/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:34:36 by marlonco          #+#    #+#             */
/*   Updated: 2025/06/12 22:33:14 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static double	scheme1(int i, int max)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i == max)
		return (BLACK);
	t = (double)i / max;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

static double	scheme2(int i, int max)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i == max)
		return (BLACK);
	t = (double)i / max;
	r = (int)(t * 255);
	g = 0;
	b = 0;
	return ((r << 16) | (g << 8) | b);
}

static double	scheme3(int i, int max)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i == max)
		return (BLACK);
	t = (double)i / max;
	r = 0;
	g = (int)(t * 255);
	b = (int)((1 - t) * 255);
	return ((r << 16) | (g << 8) | b);
}

int	calculate_color(int i, int max, int scheme)
{
	if (scheme == 0)
		return (scheme1(i, max));
	else if (scheme == 1)
		return (scheme2(i, max));
	else if (scheme == 2)
		return (scheme3(i, max));
	return (BLACK);
}
