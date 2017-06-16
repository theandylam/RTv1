/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:48:39 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 16:17:06 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	get_quadrant(int *quad, t_vec *start, t_vec *stop, t_frame *frm)
{
	pthread_mutex_lock(&frm->quadrant_mutex);
	start->z = -1;
	if (MAX_THREADS == 4)
	{
		start->x = (*quad % 2 == 0) ? 0 : (MAX_X / 2);
		start->y = (*quad < 2) ? 0 : (MAX_Y / 2);
		stop->x = (*quad % 2 == 0) ? (MAX_X / 2) : MAX_X;
		stop->y = (*quad < 2) ? (MAX_Y / 2) : MAX_Y;
	}
	else if (MAX_THREADS == 8)
	{
		start->x = (*quad % 4) * (MAX_X / 4);
		start->y = (*quad < 4) ? 0 : (MAX_Y / 2);
		stop->x = ((*quad % 4) + 1) * (MAX_X / 4);
		stop->y = (*quad < 4) ? (MAX_Y / 2) : MAX_Y;
	}
	else
		exit_program(INVALID_THREAD_COUNT);
	frm->quadrant++;
	pthread_mutex_unlock(&frm->quadrant_mutex);
}

t_vec		get_point(t_ray r, double dist)
{
	t_vec	p;

	p.x = r.org.x + (dist * r.dir.x);
	p.y = r.org.y + (dist * r.dir.y);
	p.z = r.org.z + (dist * r.dir.z);
	return (p);
}

double		get_closest_obj(t_ray r, t_shape *obj, int *obj_num, t_frame frm)
{
	int		i;
	int		closest;
	double	*distances;
	double	out;

	i = 0;
	closest = 0;
	distances = ft_memalloc(sizeof(double) * frm.scn.num_shapes);
	while (i < frm.scn.num_shapes)
	{
		distances[i] = (*frm.intersect_shape[obj[i].type])(r, obj[i]);
		i++;
	}
	i = 0;
	while (i < frm.scn.num_shapes)
	{
		if (distances[i] < distances[closest] && distances[i] > T_MIN)
			closest = i;
		i++;
	}
	*obj_num = closest;
	out = distances[closest];
	free(distances);
	distances = NULL;
	return (out);
}

void		*trace_rays(void *in)
{
	t_ray	r;
	t_frame	*frm;
	t_vec	st;
	t_vec	stop;

	frm = in;
	get_quadrant(&frm->quadrant, &st, &stop, frm);
	while (st.y < stop.y)
	{
		st.x = 0;
		while (st.x < stop.x)
		{
			r.dir.x = (2.0 * ((st.x + 0.5) / MAX_X) - 1.0) * tan(frm->cam.fov)
						* frm->cam.aspect_ratio;
			r.dir.y = (1.0 - 2.0 * ((st.y + 0.5) / MAX_Y)) * tan(frm->cam.fov);
			r.dir.z = -1;
			r.org = frm->cam.origin;
			r.dir = rotate_point(frm->cam.rotate.x, frm->cam.rotate.y,
									frm->cam.rotate.z, v_normalize(r.dir));
			color_pixel(st.x, st.y, r, *frm);
			st.x++;
		}
		st.y++;
	}
	return (NULL);
}

void		draw_image_mt(t_frame frm)
{
	int			i;
	pthread_t	fract_thread[MAX_THREADS];

	i = 0;
	while (i < MAX_THREADS)
	{
		if (pthread_create(&fract_thread[i], NULL, trace_rays, &frm))
			exit_program(P_THREAD_CREATE);
		i++;
	}
	i = 0;
	while (i < MAX_THREADS)
	{
		if (pthread_join(fract_thread[i], NULL))
			exit_program(P_THREAD_JOIN);
		i++;
	}
	mlx_put_image_to_window(frm.mlx, frm.win, frm.img.ptr, 0, 0);
}
