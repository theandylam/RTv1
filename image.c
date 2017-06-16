/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:48:39 by alam              #+#    #+#             */
/*   Updated: 2017/04/28 15:12:03 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	new_image(t_frame *frm, int x, int y)
{
	frm->img.xmax = x;
	frm->img.ymax = y;
	frm->img.ptr = mlx_new_image(frm->mlx, x, y);
	if (frm->img.ptr == NULL)
		exit_program(IMG_CREATE_ERR);
	frm->img.addr = mlx_get_data_addr(frm->img.ptr, &frm->img.bpp,
										&frm->img.line_size, &frm->img.endian);
	if (frm->img.addr == NULL)
		exit_program(IMG_DATA_ERR);
}

void	img_pxl_put(t_frame frm, int x, int y, int color)
{
	int				i;
	unsigned char	c_byte;
	unsigned int	img_color;

	i = 0;
	if (x >= frm.img.xmax || y >= frm.img.ymax || x < 0 || y < 0)
		return ;
	img_color = mlx_get_color_value(frm.mlx, color);
	while (i < (frm.img.bpp / 8))
	{
		if (frm.img.endian)
			c_byte = (img_color & (0xFF000000 >> (i * 8)))
						>> (((frm.img.bpp / 8) - i - 1) * 8);
		else
			c_byte = (img_color & (0xFF << (i * 8))) >> (i * 8);
		frm.img.addr[(x * (frm.img.bpp / 8)) + (y * frm.img.line_size) + i] =
																		c_byte;
		i++;
	}
}
