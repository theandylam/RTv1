/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:48:39 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 19:15:40 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	exit_program(int code)
{
	if (code == 0)
		ft_printf("Closing program\n");
	else if (code == INCORRECT_PARAM)
		ft_printf("Usage: ./rtv1 [1/2/3/4/5]\n");
	else if (code == MLX_INIT_ERR)
		ft_printf("Error: Failed to initialize mlx\n");
	else if (code == MLX_WIN_ERR)
		ft_printf("Error: Failed to create window\n");
	else if (code == P_THREAD_CREATE)
		ft_printf("Error: Failed to create thread\n");
	else if (code == P_THREAD_JOIN)
		ft_printf("Error: Failed to join threads\n");
	else if (code == INVALID_THREAD_COUNT)
		ft_printf("Error: Invalid MAX_THREADS value\n");
	else if (code == IMG_CREATE_ERR)
		ft_printf("Error: Failed to creating mlx image\n");
	else if (code == IMG_DATA_ERR)
		ft_printf("Error: Failed to get mlx image data\n");
	exit(0);
}

void	print_controls(void)
{
	ft_printf("  Left Click | Select object to move\n");
	ft_printf("      WASDQE | Move objects/camera\n");
	ft_printf("     [Space] | Toggle between objects/camera movement\n");
	ft_printf("      Arrows | Rotate camera\n");
	ft_printf("  Numpad +/- | Change FOV\n");
	ft_printf("Page up/down | Change exposure\n");
	ft_printf("         [~] | Reset scene\n");
	ft_printf(" [1/2/3/4/5] | Change scene\n");
	ft_printf("       F1~F4 | Change camera angle\n");
}

int		main(int argc, char **argv)
{
	t_frame	frm;

	if (argc != 2)
	{
		ft_printf("%s\n", argv[0]);
		exit_program(INCORRECT_PARAM);
	}
	frm.scene_num = ft_atoi(argv[1]);
	if (frm.scene_num < 1 || frm.scene_num > 5 || (ft_strlen(argv[1]) > 1))
		exit_program(INCORRECT_PARAM);
	print_controls();
	setup_window(&frm);
	draw_image_mt(frm);
	mlx_key_hook(frm.win, &key_hook, &frm);
	mlx_mouse_hook(frm.win, &mouse_hook, &frm);
	mlx_loop(frm.mlx);
	return (0);
}
