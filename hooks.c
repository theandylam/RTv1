/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:25:58 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 19:07:54 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	key_hook(int key, t_frame *frm)
{
	int redraw;

	redraw = 0;
	if (key == ESC || frm == NULL)
		exit_program(0);
	else if (check_key(key) == 1)
		redraw = (frm->move_cam) ? move_cam(key, frm) : move_obj(key, frm);
	else if (check_key(key) == 2)
		redraw = rotate_cam(key, frm);
	else if (check_key(key) == 3)
		redraw = change_scene_param(key, frm);
	else if (check_key(key) == 4)
		redraw = toggle_cam_movement(frm);
	else if (check_key(key) == 5)
		redraw = reset_scene(key, frm);
	else if (check_key(key) == 6)
		redraw = rot_obj(key, frm);
	else if (check_key(key) == 7)
		redraw = set_camera(key, frm);
	if (redraw)
		draw_image_mt(*frm);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_frame *frm)
{
	if (button == LEFT_CLICK)
		get_obj_at_mouse(x, y, frm);
	return (0);
}

int	expose_hook(t_frame *frm)
{
	mlx_put_image_to_window(frm->mlx, frm->win, frm->img.ptr, 0, 0);
	return (0);
}
