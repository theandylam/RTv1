/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:02:32 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 16:04:37 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	get_diffuse(t_vec hit, t_vec n, t_shape obj, t_frame frm)
{
	double	light_angle;

	light_angle = v_dot(n,
						v_normalize(v_subtract(frm.scn.light[frm.current_light]
												, hit)));
	light_angle = (light_angle < 0) ? 0 : light_angle;
	if (light_angle == 0)
		return (0);
	if (check_shadow(hit, frm))
		return (obj.k.d * light_angle);
	else
		return (0);
}

static double	get_ambient(t_vec hit, t_vec n, t_shape obj, t_frame frm)
{
	double	hit_angle;

	hit_angle = v_dot(n, v_normalize(v_subtract(frm.cam.origin, hit)));
	if (hit_angle >= 0)
		return (frm.scn.ambient * obj.k.a * hit_angle);
	else
		return (0);
}

static double	get_specular(t_vec hit, t_vec n, t_shape obj, t_frame frm)
{
	t_vec	h;
	t_vec	l;
	double	spec;

	if (obj.k.s <= 0)
		return (0);
	l = v_normalize(v_subtract(frm.scn.light[frm.current_light], hit));
	hit = v_normalize(v_subtract(frm.cam.origin, hit));
	h = v_normalize(v_add(hit, l));
	spec = pow(v_dot(h, n), obj.gloss);
	return (spec * obj.k.s);
}

int				illum(t_vec hit, t_shape *obj, int obj_num, t_frame frm)
{
	t_color		color;
	t_vec		n;
	t_lightcoef light;
	double		diffuse;

	n = get_shape_normal(hit, obj[obj_num]);
	ft_memset(&light, 0, sizeof(light));
	light.a = get_ambient(hit, n, obj[obj_num], frm);
	while (frm.current_light < frm.scn.num_lights)
	{
		diffuse = get_diffuse(hit, n, obj[obj_num], frm);
		if (diffuse > 0)
		{
			light.d += diffuse;
			light.s += get_specular(hit, n, obj[obj_num], frm);
		}
		frm.current_light++;
	}
	color.r = obj[obj_num].color.r * (light.a + light.d) + light.s * 1;
	color.g = obj[obj_num].color.g * (light.a + light.d) + light.s * 1;
	color.b = obj[obj_num].color.b * (light.a + light.d) + light.s * 1;
	color.r = 1.0f - exp(color.r * frm.exposure);
	color.g = 1.0f - exp(color.g * frm.exposure);
	color.b = 1.0f - exp(color.b * frm.exposure);
	return (color_to_int(color));
}

void			color_pixel(int x, int y, t_ray r, t_frame frm)
{
	double	dist;
	int		color;
	t_vec	hit;
	int		obj_num;

	obj_num = -1;
	dist = get_closest_obj(r, frm.scn.obj, &obj_num, frm);
	if (dist < T_MAX)
	{
		hit = get_point(r, dist);
		color = illum(hit, frm.scn.obj, obj_num, frm);
		img_pxl_put(frm, x, y, color);
	}
	else
		img_pxl_put(frm, x, y, 0);
}
