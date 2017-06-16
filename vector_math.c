/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:04:30 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 15:58:56 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	v_add(t_vec u, t_vec v)
{
	u.x += v.x;
	u.y += v.y;
	u.z += v.z;
	return (u);
}

t_vec	v_subtract(t_vec u, t_vec v)
{
	u.x -= v.x;
	u.y -= v.y;
	u.z -= v.z;
	return (u);
}

t_vec	v_cross(t_vec u, t_vec v)
{
	t_vec	cross;

	cross.x = u.y * v.z - u.z * v.y;
	cross.y = u.z * v.x - u.x * v.z;
	cross.z = u.x * v.y - u.y * v.x;
	return (cross);
}

double	v_dot(t_vec u, t_vec v)
{
	return ((u.x * v.x) + (u.y * v.y) + (u.z * v.z));
}
