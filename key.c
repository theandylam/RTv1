/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:04:24 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 19:24:23 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	check_key(int key)
{
	if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY ||
		key == Q_KEY || key == E_KEY)
		return (1);
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		return (2);
	else if (key == NUM_PLUS || key == NUM_MINUS || key == PG_UP
				|| key == PG_DWN)
		return (3);
	else if (key == SPACEBAR)
		return (4);
	else if (key == TILDE || key == KEY_1 || key == KEY_2 || key == KEY_3 ||
				key == KEY_4 || key == KEY_5)
		return (5);
	else if ((key > NUM_3 && key < 90) || key == NUM_8 || key == NUM_9)
		return (6);
	else if (key == F1 || key == F2 || key == F3 || key == F4)
		return (7);
	else
		return (0);
}

int	reset_scene(int key, t_frame *frm)
{
	if (key == KEY_1)
		frm->scene_num = 1;
	else if (key == KEY_2)
		frm->scene_num = 2;
	else if (key == KEY_3)
		frm->scene_num = 3;
	else if (key == KEY_4)
		frm->scene_num = 4;
	else if (key == KEY_5)
		frm->scene_num = 5;
	free(frm->scn.obj);
	free(frm->scn.light);
	frm->scn.obj = NULL;
	frm->scn.light = NULL;
	set_scene(frm->scene_num, frm);
	if (key == TILDE)
		ft_printf("Resetting scene\n");
	else
		ft_printf("Loading scene %d\n", frm->scene_num);
	return (1);
}

int	change_scene_param(int key, t_frame *frm)
{
	if (key == NUM_PLUS)
		frm->cam.fov += 5.0f * (M_PI / 180.0f);
	else if (key == NUM_MINUS)
		frm->cam.fov -= 5.0f * (M_PI / 180.0f);
	else if (key == PG_UP)
		frm->exposure -= 0.1;
	else if (key == PG_DWN)
		frm->exposure += 0.1;
	return (1);
}

int	set_camera(int key, t_frame *frm)
{
	if (key == F1)
	{
		ft_printf("Loading camera angle 1\n");
		init_cam(frm, vec(0, 0, 200), vec(0, 0, 0), 90);
	}
	else if (key == F2)
	{
		ft_printf("Loading camera angle 2\n");
		init_cam(frm, vec(200, 100, 0), vec(-22.5, 45.0, 0), 90);
	}
	else if (key == F3)
	{
		ft_printf("Loading camera angle 3\n");
		init_cam(frm, vec(0, 600, 0), vec(-75.0, 0, 0), 90);
	}
	else if (key == F4)
	{
		ft_printf("Loading camera angle 4\n");
		init_cam(frm, vec(-300, 0, 100), vec(0, -75.0, 0), 90);
	}
	return (1);
}

int	toggle_cam_movement(t_frame *frm)
{
	frm->move_cam ^= 1;
	ft_printf("Moving ");
	if (frm->move_cam)
		ft_printf("camera\n");
	else
		ft_printf("object #%d\n", frm->current_obj);
	return (0);
}
