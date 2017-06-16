/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:48:39 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 15:33:29 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		gradient(double iter, int max, int bot_c, int top_c)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				shift;

	if (iter > MAX_ITER)
		iter = MAX_ITER;
	shift = (((top_c & R_MSK) >> 16) - ((bot_c & R_MSK) >> 16))
			* (iter / (max));
	r = ((bot_c & R_MSK) >> 16) + shift;
	shift = (((top_c & G_MSK) >> 8) - ((bot_c & G_MSK) >> 8))
			* (iter / (max));
	g = ((bot_c & G_MSK) >> 8) + shift;
	shift = (((top_c & B_MSK) >> 0) - ((bot_c & B_MSK) >> 0))
			* (iter / (max));
	b = ((bot_c & B_MSK) >> 0) + shift;
	return ((r << 16) + (g << 8) + b);
}

int		color(double iter)
{
	int	step;

	step = MAX_ITER / 4;
	if (iter < step)
		return (gradient(iter, step, PURPLE, YELLOW));
	else if (iter < (2 * step))
		return (gradient(iter - step, step, YELLOW, CYAN));
	else if (iter < (3 * step))
		return (gradient(iter - (2 * step), step, CYAN, MAGENTA));
	else
		return (gradient(iter - (3 * step), step, MAGENTA, WHITE));
}

int		color_to_int(t_color c)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	c.r = (c.r > 1.0f) ? 1.0f : c.r;
	c.g = (c.g > 1.0f) ? 1.0f : c.g;
	c.b = (c.b > 1.0f) ? 1.0f : c.b;
	c.r = (c.r < 0.0f) ? 0.0f : c.r;
	c.g = (c.g < 0.0f) ? 0.0f : c.g;
	c.b = (c.b < 0.0f) ? 0.0f : c.b;
	r = (c.r / 1.0f) * 255;
	g = (c.g / 1.0f) * 255;
	b = (c.b / 1.0f) * 255;
	return ((r << 16) + (g << 8) + b);
}

t_color	int_to_color(int n)
{
	t_color			c;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = ((n & R_MSK) >> 16);
	g = ((n & G_MSK) >> 8);
	b = ((n & B_MSK) >> 0);
	c.r = r / 256.0f;
	c.g = g / 256.0f;
	c.b = b / 256.0f;
	return (c);
}
