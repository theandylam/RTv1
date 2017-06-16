/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:48:39 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 18:59:40 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_cam(t_frame *frm, t_vec p, t_vec rot, double fov)
{
	frm->cam.origin = p;
	frm->cam.rotate.x = rot.x * (M_PI / 180);
	frm->cam.rotate.y = rot.y * (M_PI / 180);
	frm->cam.rotate.z = rot.z * (M_PI / 180);
	frm->cam.aspect_ratio = (double)MAX_X / (double)MAX_Y;
	frm->cam.fov = (fov / 2.0f) * (M_PI / 180.0f);
}

void	set_scene(int scene, t_frame *frm)
{
	if (scene == 1)
		scene1(frm);
	else if (scene == 2)
		scene2(frm);
	else if (scene == 3)
		scene3(frm);
	else if (scene == 4)
		scene4(frm);
	else if (scene == 5)
		scene5(frm);
}

void	setup_window(t_frame *frm)
{
	frm->mlx = mlx_init();
	if (frm->mlx == NULL)
		exit_program(MLX_INIT_ERR);
	frm->win = mlx_new_window(frm->mlx, MAX_X, MAX_Y, "RTv1");
	if (frm->win == NULL)
		exit_program(MLX_WIN_ERR);
	new_image(frm, MAX_X, MAX_Y);
	set_scene(frm->scene_num, frm);
	frm->current_obj = 0;
	frm->current_light = 0;
	frm->quadrant = 0;
	frm->move_cam = 0;
	frm->intersect_shape[0] = &intersect_sphere;
	frm->intersect_shape[1] = &intersect_plane;
	frm->intersect_shape[2] = &intersect_cylinder;
	frm->intersect_shape[3] = &intersect_cone;
}
