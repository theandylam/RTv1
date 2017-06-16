/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 17:28:37 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 18:57:26 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	scene1(t_frame *frm)
{
	frm->scn.num_shapes = 7;
	frm->scn.obj = ft_memalloc(sizeof(t_shape) * frm->scn.num_shapes);
	frm->scn.obj[0] = new_sph(vec(0, -100, -100), 25, CYAN);
	frm->scn.obj[1] = new_pln(vec(0, 200, 0), vec(0, 199, 0), RED);
	frm->scn.obj[2] = new_pln(vec(0, -200, 0), vec(0, -199, 0), MAGENTA);
	frm->scn.obj[3] = new_pln(vec(-200, 0, 0), vec(-199, 0, 0), BLUE);
	frm->scn.obj[4] = new_pln(vec(200, 0, 0), vec(199, 0, 0), CYAN);
	frm->scn.obj[5] = new_pln(vec(0, 0, -200), vec(0, 0, -199), GREEN);
	frm->scn.obj[6] = new_pln(vec(0, 0, 200), vec(0, 0, 199), YELLOW);
	frm->scn.ambient = 0.5;
	frm->scn.num_lights = 2;
	frm->scn.light = ft_memalloc(sizeof(t_vec) * frm->scn.num_lights);
	frm->scn.light[0] = vec(100, 100, -100);
	frm->scn.light[1] = vec(-100, 100, -100);
	frm->exposure = -1.00f;
	init_cam(frm, vec(0, 0, 150), vec(0, 0, 0), 90);
}

void	scene2(t_frame *frm)
{
	frm->scn.num_shapes = 5;
	frm->scn.obj = ft_memalloc(sizeof(t_shape) * frm->scn.num_shapes);
	frm->scn.obj[0] = new_pln(vec(0, -100, 0), vec(0, -99, 0), GREY);
	frm->scn.obj[1] = new_pln(vec(0, 0, -300), vec(0, 0, -299), GREY);
	frm->scn.obj[2] = new_sph(vec(0, 0, -100), 75, CYAN);
	frm->scn.obj[3] = new_cyl(vec(-50, 0, -100), vec(0, 1, 0), 40, MAGENTA);
	frm->scn.obj[3].d = rotate_point(-15 * (M_PI / 180), 0, -30 * (M_PI / 180),
										frm->scn.obj[3].d);
	frm->scn.obj[4] = new_cone(vec(50, 0, -100), vec(0, 0, 45), YELLOW);
	frm->scn.ambient = 0.8;
	frm->scn.num_lights = 1;
	frm->scn.light = ft_memalloc(sizeof(t_vec) * frm->scn.num_lights);
	frm->scn.light[0] = vec(1000, 100, 100);
	frm->exposure = -1.00f;
	init_cam(frm, vec(0, 0, 200), vec(0, 0, 0), 90);
}

void	scene3(t_frame *frm)
{
	frm->scn.num_shapes = 16;
	frm->scn.obj = ft_memalloc(sizeof(t_shape) * frm->scn.num_shapes);
	frm->scn.obj[0] = new_sph(vec(0, -50, 0), 15, RED);
	frm->scn.obj[1] = new_pln(vec(0, 0, -400), vec(0, 0, -399), BLUE);
	frm->scn.obj[2] = new_pln(vec(0, 100, 0), vec(0, 99, 0), DARK_GREY);
	frm->scn.obj[3] = new_pln(vec(0, -100, 0), vec(0, -99, 0), GREY);
	frm->scn.obj[8] = new_sph(vec(-100, 100, 25), 30, SILVER);
	frm->scn.obj[4] = new_cyl(vec(-100, 0, 25), vec(0, 1, 0), 20, SILVER);
	frm->scn.obj[9] = new_sph(vec(-100, -100, 25), 30, SILVER);
	frm->scn.obj[10] = new_sph(vec(100, 100, 25), 30, SILVER);
	frm->scn.obj[5] = new_cyl(vec(100, 0, 25), vec(0, 1, 0), 20, SILVER);
	frm->scn.obj[11] = new_sph(vec(100, -100, 25), 30, SILVER);
	frm->scn.obj[12] = new_sph(vec(-100, 100, -150), 30, SILVER);
	frm->scn.obj[6] = new_cyl(vec(-100, 0, -150), vec(0, 1, 0), 20, SILVER);
	frm->scn.obj[13] = new_sph(vec(-100, -100, -150), 30, SILVER);
	frm->scn.obj[14] = new_sph(vec(100, 100, -150), 30, SILVER);
	frm->scn.obj[7] = new_cyl(vec(100, 0, -150), vec(0, 1, 0), 20, SILVER);
	frm->scn.obj[15] = new_sph(vec(100, -100, -150), 30, SILVER);
	frm->scn.ambient = 0.2;
	frm->scn.num_lights = 2;
	frm->scn.light = ft_memalloc(sizeof(t_vec) * frm->scn.num_lights);
	frm->scn.light[0] = vec(-200, 90, 175);
	frm->scn.light[1] = vec(200, 90, 175);
	frm->exposure = -1.00f;
	init_cam(frm, vec(0, 0, 500), vec(0, 0, 0), 50);
}

void	scene4(t_frame *frm)
{
	frm->scn.num_shapes = 8;
	frm->scn.obj = ft_memalloc(sizeof(t_shape) * frm->scn.num_shapes);
	frm->scn.obj[0] = new_pln(vec(0, -200, 0), vec(0, -199, 0), GREY);
	frm->scn.obj[1] = new_pln(vec(0, 0, -300), vec(0, 0, -299), GREY);
	frm->scn.obj[2] = new_sph(vec(0, 100, -100), 25, RED);
	frm->scn.obj[3] = new_sph(vec(100, -50, -100), 25, GREEN);
	frm->scn.obj[4] = new_sph(vec(-100, -50, -100), 25, BLUE);
	frm->scn.obj[5] = new_sph(vec(100, 50, -100), 25, YELLOW);
	frm->scn.obj[6] = new_sph(vec(-100, 50, -100), 25, MAGENTA);
	frm->scn.obj[7] = new_sph(vec(0, -100, -100), 25, CYAN);
	frm->scn.ambient = 0.8;
	frm->scn.num_lights = 2;
	frm->scn.light = ft_memalloc(sizeof(t_vec) * frm->scn.num_lights);
	frm->scn.light[0] = vec(0, 0, 0);
	frm->scn.light[1] = vec(0, 0, 200);
	frm->exposure = -1.00f;
	init_cam(frm, vec(0, 0, 500), vec(0, 0, 0), 60);
}

void	scene5(t_frame *frm)
{
	frm->scn.num_shapes = 2;
	frm->scn.obj = ft_memalloc(sizeof(t_shape) * frm->scn.num_shapes);
	frm->scn.obj[0] = new_pln(vec(0, -200, 0), vec(0, -199, 0), GREY);
	frm->scn.obj[1] = new_sph(vec(0, -100, -100), 50, CYAN);
	frm->scn.ambient = 0.8;
	frm->scn.num_lights = 5;
	frm->scn.light = ft_memalloc(sizeof(t_vec) * frm->scn.num_lights);
	frm->scn.light[0] = vec(0, 0, 500);
	frm->scn.light[1] = vec(0, 125, 375);
	frm->scn.light[2] = vec(0, 250, 250);
	frm->scn.light[3] = vec(0, 375, 125);
	frm->scn.light[4] = vec(0, 500, 0);
	frm->exposure = -1.00f;
	init_cam(frm, vec(-600, 200, 500), vec(-22.5, -45.0, 0), 60);
}
