/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 19:02:35 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 19:02:27 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include "libft/libft.h"

# define MAX_X 1280
# define MAX_Y 720
# define MAX_THREADS 8
# define MAX_ITER 256

# define CYAN 0x0000FFFF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define WHITE 0x00FFFFFF
# define DARK_GREY 0x009F9F9F
# define GREY 0x00F0F0F0
# define SILVER 0x00F7F7F7
# define PURPLE 0x008A2BE2
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

# define R_MSK 0x00FF0000
# define G_MSK 0x0000FF00
# define B_MSK 0x000000FF

# define T_MIN 0.0001f
# define T_MAX 100000.0f

# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define SCRL_UP 4
# define SCRL_DN 5

# define ESC 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define Q_KEY 12
# define E_KEY 14
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define NUM_PLUS 69
# define NUM_MINUS 78
# define NUM_0 82
# define NUM_1 83
# define NUM_2 84
# define NUM_3 85
# define NUM_4 86
# define NUM_5 87
# define NUM_6 88
# define NUM_7 89
# define NUM_8 91
# define NUM_9 92
# define SPACEBAR 49
# define TILDE 50
# define PG_UP 116
# define PG_DWN 121
# define HOME 115
# define END 119

# define F1 122
# define F2 120
# define F3 99
# define F4 118

# define INCORRECT_PARAM 1
# define MLX_INIT_ERR 2
# define MLX_WIN_ERR 3
# define P_THREAD_CREATE 4
# define P_THREAD_JOIN 5
# define INVALID_THREAD_COUNT 6
# define IMG_CREATE_ERR 7
# define IMG_DATA_ERR 8

# define SQR(x) x * x

typedef struct	s_vec
{
	double x;
	double y;
	double z;
}				t_vec;

typedef struct	s_color
{
	double r;
	double g;
	double b;
}				t_color;

typedef struct	s_ray
{
	t_vec	org;
	t_vec	dir;
}				t_ray;

typedef struct	s_mlx
{
	void *mlx;
	void *win;
}				t_mlx;

typedef struct	s_camera
{
	t_vec		origin;
	t_vec		rotate;
	double		aspect_ratio;
	double		fov;
}				t_camera;

typedef struct	s_lightcoef
{
	double		a;
	double		d;
	double		s;
}				t_lightcoef;

typedef struct	s_shape
{
	int			type;
	t_color		color;
	t_lightcoef	k;
	double		diffuse;
	double		gloss;

	t_vec		c;
	t_vec		d;

	double		sph_r;

	double		cyl_r;
	t_vec		cyl_rot;

	double		cone_angle;
	t_vec		cone_rot;
}				t_shape;

typedef struct	s_img
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			line_size;
	int			endian;
	int			xmax;
	int			ymax;
}				t_img;

typedef struct	s_scene
{
	t_shape		*obj;
	int			num_shapes;

	t_vec		*light;
	int			num_lights;

	double		ambient;
}				t_scene;

typedef struct	s_frame
{
	void			*mlx;
	void			*win;

	t_scene			scn;
	t_camera		cam;

	double			exposure;
	int				current_obj;
	int				current_light;

	t_img			img;

	pthread_mutex_t	quadrant_mutex;
	int				quadrant;

	double			(*intersect_shape[4])(t_ray, t_shape);

	int				move_cam;
	int				scene_num;
}				t_frame;

/*
**				-----------------
**				|	rtv1.c		|
**				-----------------
*/
void			exit_program(int code);
void			print_controls(void);

/*
**				-----------------
**				|	init.c		|
**				-----------------
*/
void			init_cam(t_frame *frm, t_vec p, t_vec rot, double fov);
void			set_scene(int scene, t_frame *frm);
void			scene1(t_frame *frm);
void			scene2(t_frame *frm);
void			scene3(t_frame *frm);
void			setup_window(t_frame *frm);

/*
**				-----------------
**				|	scenes.c	|
**				-----------------
*/
void			scene1(t_frame *frm);
void			scene2(t_frame *frm);
void			scene3(t_frame *frm);
void			scene4(t_frame *frm);
void			scene5(t_frame *frm);

/*
**				---------------------
**				|	init_shapes.c	|
**				---------------------
*/
t_shape			new_sph(t_vec pos, double r, int color);
t_shape			new_pln(t_vec pt, t_vec dir, int color);
t_shape			new_cyl(t_vec pt, t_vec dir, double r, int color);
t_shape			new_cone(t_vec pt, t_vec rot, int color);

/*
**				-----------------
**				|	draw.c		|
**				-----------------
*/
t_vec			get_point(t_ray r, double dist);
double			get_closest_obj(t_ray r, t_shape *obj,
								int *obj_num, t_frame frm);
void			*trace_rays(void *in);
void			draw_image_mt(t_frame frm);

/*
**				-----------------
**				|	color.c		|
**				-----------------
*/
int				gradient(double iter, int max, int bot_c, int top_c);
int				color(double iter);
int				color_to_int(t_color c);
t_color			int_to_color(int n);

/*
**				-----------------
**				|	image.c		|
**				-----------------
*/
void			new_image(t_frame *frm, int x, int y);
void			img_pxl_put(t_frame frm, int x, int y, int color);

/*
**				-----------------
**				|	hooks.c		|
**				-----------------
*/
int				key_hook(int key, t_frame *frm);
int				mouse_hook(int button, int x, int y, t_frame *frm);
int				expose_hook(t_frame *frm);

/*
**				-----------------
**				|	intersect.c	|
**				-----------------
*/
double			intersect_sphere(t_ray r, t_shape s);
double			intersect_plane(t_ray r, t_shape s);
double			intersect_cylinder(t_ray r, t_shape s);
double			intersect_cone(t_ray r, t_shape s);

/*
**				-----------------
**				|	key.c		|
**				-----------------
*/
int				check_key(int key);
int				toggle_cam_movement(t_frame *frm);
int				change_scene_param(int key, t_frame *frm);
int				reset_scene(int key, t_frame *frm);
int				set_camera(int key, t_frame *frm);

/*
**				-----------------
**				|	key_move.c	|
**				-----------------
*/
int				move_obj(int key, t_frame *frm);
int				rot_obj(int key, t_frame *frm);
int				move_cam(int key, t_frame *frm);
int				rotate_cam(int key, t_frame *frm);

/*
**				-----------------
**				|	lighting.c	|
**				-----------------
*/
int				illum(t_vec hit, t_shape *obj, int obj_num, t_frame frm);
void			color_pixel(int x, int y, t_ray r, t_frame frm);

/*
**				-----------------
**				|	lighting_2.c|
**				-----------------
*/
t_vec			get_shape_normal(t_vec hit, t_shape obj);
int				check_shadow(t_vec hit, t_frame frm);

/*
**				-----------------
**				|	mouse.c		|
**				-----------------
*/
void			get_obj_at_mouse(int x, int y, t_frame *frm);

/*
**				-----------------
**				|	ui.c		|
**				-----------------
*/
void			draw_ui(t_frame frm);

/*
**				---------------------
**				|	vector_math.c	|
**				---------------------
*/
t_vec			v_add(t_vec u, t_vec v);
t_vec			v_subtract(t_vec u, t_vec v);
double			v_dot(t_vec u, t_vec v);
t_vec			v_cross(t_vec u, t_vec v);

/*
**				---------------------
**				|	vector_scalar.c	|
**				---------------------
*/
t_vec			v_scalar_add(t_vec pt, double n);
t_vec			v_scalar_sub(t_vec pt, double n);
t_vec			v_scalar_mult(t_vec pt, double n);
t_vec			v_scalar_div(t_vec u, double d);

/*
**				---------------------
**				|	vector_ops.c	|
**				---------------------
*/
t_vec			v_matrix_mult(double mat[4][4], t_vec pt);
t_vec			v_normalize(t_vec v);
double			v_distance(t_vec u, t_vec v);
t_vec			vec(double x, double y, double z);
t_vec			v_project(t_vec u, t_vec v);

/*
**				---------------------
**				|	vector_rotate.c	|
**				---------------------
*/
t_vec			rotate_x(t_vec pt, double theta);
t_vec			rotate_y(t_vec pt, double theta);
t_vec			rotate_z(t_vec pt, double theta);
t_vec			rotate_point(double alpha, double beta, double gamma, t_vec pt);

#endif
