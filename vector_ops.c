/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:08:49 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 15:58:32 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	v_matrix_mult(double mat[4][4], t_vec pt)
{
	t_vec	out;

	out.x = (mat[0][0] * pt.x) + (mat[1][0] * pt.y) +
			(mat[2][0] * pt.z) + (mat[3][0] * 1);
	out.y = (mat[0][1] * pt.x) + (mat[1][1] * pt.y) +
			(mat[2][1] * pt.z) + (mat[3][1] * 1);
	out.z = (mat[0][2] * pt.x) + (mat[1][2] * pt.y) +
			(mat[2][2] * pt.z) + (mat[3][2] * 1);
	return (out);
}

t_vec	v_normalize(t_vec v)
{
	double	mag;

	mag = sqrt(SQR(v.x) + SQR(v.y) + SQR(v.z));
	v.x = v.x / mag;
	v.y = v.y / mag;
	v.z = v.z / mag;
	return (v);
}

t_vec	v_project(t_vec u, t_vec v)
{
	t_vec	proj;
	double	dot;

	dot = v_dot(u, v) / v_dot(v, v);
	proj = v_scalar_mult(v, dot);
	return (proj);
}

double	v_distance(t_vec u, t_vec v)
{
	return (sqrt(SQR((u.x - v.x)) + SQR((u.y - v.y)) + SQR((u.z - v.z))));
}

t_vec	vec(double x, double y, double z)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}
