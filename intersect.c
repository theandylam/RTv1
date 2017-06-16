/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:30:11 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 16:13:12 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		intersect_sphere(t_ray r, t_shape s)
{
	t_vec	q;
	t_vec	d;
	double	disc;
	double	t;

	d = r.dir;
	q.x = (SQR(d.x)) + (SQR(d.y)) + (SQR(d.z));
	q.y = 2.0f * d.x * (r.org.x - s.c.x) + 2.0f * d.y * (r.org.y - s.c.y)
			+ 2.0f * d.z * (r.org.z - s.c.z);
	q.z = (SQR(s.c.x)) + (SQR(s.c.y)) + (SQR(s.c.z))
		+ (SQR(r.org.x)) + (SQR(r.org.y)) + (SQR(r.org.z))
		+ (-2.0f * (s.c.x * r.org.x + s.c.y * r.org.y + s.c.z * r.org.z))
		- (SQR(s.sph_r));
	disc = (SQR(q.y)) - (4.0f * q.x * q.z);
	if (disc < 0)
		return (T_MAX);
	t = (-q.y - sqrt(disc)) / (2.0f * q.x);
	if (t > T_MAX || t < T_MIN)
		return (T_MAX);
	return (t);
}

double		intersect_plane(t_ray r, t_shape s)
{
	double	t;
	double	ddotv;
	double	xdotv;
	t_vec	x;

	x = v_subtract(r.org, s.c);
	ddotv = v_dot(r.dir, s.d);
	xdotv = v_dot(x, s.d);
	if (ddotv != 0)
	{
		t = -xdotv / ddotv;
		if (t > T_MIN && t < T_MAX)
			return (t);
	}
	return (T_MAX);
}

double		intersect_cylinder(t_ray r, t_shape s)
{
	t_vec	q;
	double	disc;
	double	t;
	t_vec	x;

	x = v_subtract(r.org, s.c);
	q.x = v_dot(r.dir, r.dir) - (v_dot(r.dir, s.d) * v_dot(r.dir, s.d));
	q.y = v_dot(r.dir, x) - (v_dot(r.dir, s.d) * v_dot(x, s.d));
	q.y *= 2;
	q.z = v_dot(x, x) - (v_dot(x, s.d) * v_dot(x, s.d)) - (SQR(s.cyl_r));
	disc = (SQR(q.y)) - (4.0f * q.x * q.z);
	t = (-q.y - sqrt(disc)) / (2.0f * q.x);
	if (t > T_MAX || t < T_MIN)
		return (T_MAX);
	return (t);
}

double		intersect_cone(t_ray r, t_shape s)
{
	t_vec	q;
	t_vec	x;
	double	disc;
	double	t;
	double	k;

	x = v_subtract(r.org, s.c);
	k = tan(s.cone_angle);
	q.x = v_dot(r.dir, r.dir) - (1 + k * k) * (SQR(v_dot(r.dir, s.d)));
	q.y = v_dot(r.dir, x) - (1 + (SQR(k)))
			* v_dot(r.dir, s.d) * v_dot(x, s.d);
	q.y *= 2;
	q.z = v_dot(x, x) - (1 + (SQR(k))) * (SQR(v_dot(x, s.d)));
	disc = (SQR(q.y)) - (4.0f * q.x * q.z);
	if (disc < 0)
		return (T_MAX);
	t = (-q.y - sqrt(disc)) / (2.0f * q.x);
	if (t > T_MAX || t < T_MIN)
		return (T_MAX);
	return (t);
}
