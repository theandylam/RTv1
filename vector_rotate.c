/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <alam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:25:38 by alam              #+#    #+#             */
/*   Updated: 2017/06/05 15:56:13 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	rotate_x(t_vec pt, double theta)
{
	double mat[4][4];

	mat[0][0] = 1;
	mat[1][0] = 0;
	mat[2][0] = 0;
	mat[3][0] = 0;
	mat[0][1] = 0;
	mat[1][1] = cos(theta);
	mat[2][1] = -sin(theta);
	mat[3][1] = 0;
	mat[0][2] = 0;
	mat[1][2] = sin(theta);
	mat[2][2] = cos(theta);
	mat[3][2] = 0;
	mat[0][3] = 0;
	mat[1][3] = 0;
	mat[2][3] = 0;
	mat[3][3] = 1;
	return (v_matrix_mult(mat, pt));
}

t_vec	rotate_y(t_vec pt, double theta)
{
	double mat[4][4];

	mat[0][0] = cos(theta);
	mat[1][0] = 0;
	mat[2][0] = sin(theta);
	mat[3][0] = 0;
	mat[0][1] = 0;
	mat[1][1] = 1;
	mat[2][1] = 0;
	mat[3][1] = 0;
	mat[0][2] = -sin(theta);
	mat[1][2] = 0;
	mat[2][2] = cos(theta);
	mat[3][2] = 0;
	mat[0][3] = 0;
	mat[1][3] = 0;
	mat[2][3] = 0;
	mat[3][3] = 1;
	return (v_matrix_mult(mat, pt));
}

t_vec	rotate_z(t_vec pt, double theta)
{
	double mat[4][4];

	mat[0][0] = cos(theta);
	mat[1][0] = -sin(theta);
	mat[2][0] = 0;
	mat[3][0] = 0;
	mat[0][1] = sin(theta);
	mat[1][1] = cos(theta);
	mat[2][1] = 0;
	mat[3][1] = 0;
	mat[0][2] = 0;
	mat[1][2] = 0;
	mat[2][2] = 1;
	mat[3][2] = 0;
	mat[0][3] = 0;
	mat[1][3] = 0;
	mat[2][3] = 0;
	mat[3][3] = 1;
	return (v_matrix_mult(mat, pt));
}

t_vec	rotate_point(double alpha, double beta, double gamma, t_vec pt)
{
	double mat[4][4];

	mat[0][0] = cos(beta) * cos(gamma);
	mat[1][0] = cos(gamma) * sin(alpha) * sin(beta) - cos(alpha) * sin(gamma);
	mat[2][0] = cos(alpha) * cos(gamma) * sin(beta) + sin(alpha) * sin(gamma);
	mat[3][0] = 0;
	mat[0][1] = cos(beta) * sin(gamma);
	mat[1][1] = cos(alpha) * cos(gamma) + sin(alpha) * sin(beta) * sin(gamma);
	mat[2][1] = -cos(gamma) * sin(alpha) + cos(alpha) * sin(beta) * sin(gamma);
	mat[3][1] = 0;
	mat[0][2] = -sin(beta);
	mat[1][2] = cos(beta) * sin(alpha);
	mat[2][2] = cos(alpha) * cos(beta);
	mat[3][2] = 0;
	mat[0][3] = 0;
	mat[1][3] = 0;
	mat[2][3] = 0;
	mat[3][3] = 1;
	return (v_matrix_mult(mat, pt));
}
