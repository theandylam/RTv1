/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:04:24 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 19:08:12 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_obj_at_mouse(int x, int y, t_frame *frm)
{
	t_ray	r;
	int		obj_num;
	double	dist;

	obj_num = 0;
	r.dir.x = (2.0 * ((x + 0.5) / MAX_X) - 1.0) * tan(frm->cam.fov)
				* frm->cam.aspect_ratio;
	r.dir.y = (1.0 - 2.0 * ((y + 0.5) / MAX_Y)) * tan(frm->cam.fov);
	r.dir.z = -1;
	r.org = frm->cam.origin;
	r.dir = rotate_point(frm->cam.rotate.x, frm->cam.rotate.y,
							frm->cam.rotate.z, v_normalize(r.dir));
	dist = get_closest_obj(r, frm->scn.obj, &obj_num, *frm);
	frm->current_obj = obj_num;
	ft_printf("Selected object: %d\n", frm->current_obj);
}
