/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:02:32 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 16:08:34 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	get_shape_normal(t_vec hit, t_shape obj)
{
	t_vec	n;
	t_vec	proj;
	double	k;

	n = vec(0, 0, 0);
	k = 0;
	if (obj.type == 0)
		n = v_normalize(v_subtract(hit, obj.c));
	else if (obj.type == 1)
		n = obj.d;
	else if (obj.type == 2)
	{
		n = v_subtract(hit, obj.c);
		proj = v_project(n, obj.d);
		n = v_normalize(v_subtract(n, proj));
	}
	else if (obj.type == 3)
	{
		n = v_subtract(hit, obj.c);
		proj = v_project(n, obj.d);
		k = 1 + tan(obj.cone_angle) * tan(obj.cone_angle);
		proj = v_scalar_mult(proj, k);
		n = v_normalize(v_subtract(n, proj));
	}
	return (n);
}

int		check_shadow(t_vec hit, t_frame frm)
{
	int		obj_num;
	t_ray	r;
	double	dist;
	double	light_dist;

	obj_num = -1;
	r.org = hit;
	r.dir = v_normalize(v_subtract(frm.scn.light[frm.current_light], hit));
	dist = get_closest_obj(r, frm.scn.obj, &obj_num, frm);
	if (dist < T_MAX && dist > T_MIN)
	{
		light_dist = v_distance(frm.scn.light[frm.current_light], hit);
		if (dist < light_dist)
			return (0);
	}
	return (1);
}
