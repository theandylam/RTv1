/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 14:28:19 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 16:05:27 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	move_obj(int key, t_frame *frm)
{
	if (frm->scn.obj[frm->current_obj].type < 0
		|| frm->scn.obj[frm->current_obj].type > 3)
		return (0);
	if (key == W_KEY)
		frm->scn.obj[frm->current_obj].c.z -= 25;
	else if (key == S_KEY)
		frm->scn.obj[frm->current_obj].c.z += 25;
	else if (key == A_KEY)
		frm->scn.obj[frm->current_obj].c.x -= 25;
	else if (key == D_KEY)
		frm->scn.obj[frm->current_obj].c.x += 25;
	else if (key == E_KEY)
		frm->scn.obj[frm->current_obj].c.y -= 25;
	else if (key == Q_KEY)
		frm->scn.obj[frm->current_obj].c.y += 25;
	return (1);
}

int	rot_obj(int key, t_frame *frm)
{
	t_vec	d;
	double	angle;

	if (frm->scn.obj[frm->current_obj].type < 0
		|| frm->scn.obj[frm->current_obj].type > 3)
		return (0);
	d = frm->scn.obj[frm->current_obj].d;
	angle = 10.0f * (M_PI / 180);
	if (key == NUM_8)
		d = rotate_point(-angle, 0, 0, d);
	else if (key == NUM_5)
		d = rotate_point(angle, 0, 0, d);
	else if (key == NUM_4)
		d = rotate_point(0, 0, angle, d);
	else if (key == NUM_6)
		d = rotate_point(0, 0, -angle, d);
	else if (key == NUM_7)
		d = rotate_point(0, -angle, 0, d);
	else if (key == NUM_9)
		d = rotate_point(0, angle, 0, d);
	frm->scn.obj[frm->current_obj].d = d;
	return (1);
}

int	move_cam(int key, t_frame *frm)
{
	if (key == W_KEY)
		frm->cam.origin.z -= 50;
	else if (key == S_KEY)
		frm->cam.origin.z += 50;
	else if (key == A_KEY)
		frm->cam.origin.x -= 50;
	else if (key == D_KEY)
		frm->cam.origin.x += 50;
	else if (key == E_KEY)
		frm->cam.origin.y -= 50;
	else if (key == Q_KEY)
		frm->cam.origin.y += 50;
	return (1);
}

int	rotate_cam(int key, t_frame *frm)
{
	if (key == UP)
		frm->cam.rotate.x += 22.5f * (M_PI / 180);
	else if (key == DOWN)
		frm->cam.rotate.x -= 22.5f * (M_PI / 180);
	else if (key == LEFT)
		frm->cam.rotate.y += 22.5f * (M_PI / 180);
	else if (key == RIGHT)
		frm->cam.rotate.y -= 22.5f * (M_PI / 180);
	return (1);
}
