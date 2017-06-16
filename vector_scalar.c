/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 17:30:55 by alam              #+#    #+#             */
/*   Updated: 2017/06/04 18:09:08 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	v_scalar_add(t_vec pt, double n)
{
	pt.x += n;
	pt.y += n;
	pt.z += n;
	return (pt);
}

t_vec	v_scalar_sub(t_vec pt, double n)
{
	pt.x -= n;
	pt.y -= n;
	pt.z -= n;
	return (pt);
}

t_vec	v_scalar_mult(t_vec pt, double n)
{
	pt.x *= n;
	pt.y *= n;
	pt.z *= n;
	return (pt);
}

t_vec	v_scalar_div(t_vec u, double d)
{
	t_vec	out;

	out.x = u.x / d;
	out.y = u.y / d;
	out.z = u.z / d;
	return (out);
}
