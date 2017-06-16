/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 17:07:03 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 17:22:27 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_shape	new_sph(t_vec pos, double r, int color)
{
	t_shape	out;

	out.type = 0;
	out.color = int_to_color(color);
	out.k.a = 1;
	out.k.d = 0.9;
	out.k.s = 0.9;
	out.gloss = 100;
	out.c = pos;
	out.sph_r = r;
	return (out);
}

t_shape	new_pln(t_vec pt, t_vec dir, int color)
{
	t_shape	out;

	out.type = 1;
	out.color = int_to_color(color);
	out.k.a = 0.4;
	out.k.d = 0.6;
	out.k.s = 0.2;
	out.gloss = 10;
	out.c = pt;
	out.d = dir;
	out.d = v_normalize(v_subtract(out.d, out.c));
	return (out);
}

t_shape	new_cyl(t_vec pt, t_vec dir, double r, int color)
{
	t_shape	out;

	out.type = 2;
	out.color = int_to_color(color);
	out.k.a = 0.7;
	out.k.d = 0.6;
	out.k.s = 0.7;
	out.gloss = 50;
	out.c = pt;
	out.d = dir;
	out.cyl_r = r;
	return (out);
}

t_shape	new_cone(t_vec pt, t_vec rot, int color)
{
	t_shape	out;

	out.type = 3;
	out.color = int_to_color(color);
	out.k.a = 1;
	out.k.d = 0.6;
	out.k.s = 0.8;
	out.gloss = 75;
	out.c = pt;
	out.cone_rot = rot;
	out.cone_angle = 22.5f * (M_PI / 180);
	out.d = vec(0, 1, 0);
	out.d = rotate_point(out.cone_rot.x, out.cone_rot.y, out.cone_rot.z, out.d);
	return (out);
}
