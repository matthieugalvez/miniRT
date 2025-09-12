/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_operator2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:20:06 by mgalvez           #+#    #+#             */
/*   Updated: 2025/09/11 19:27:01 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_coordinates	pyramid_normal(t_element *cone, t_coordinates *point)
{
	t_coordinates	buf_vec;
	double			t;
	t_coordinates	circle_center;
	double			factor;
	t_coordinates	normal_at_vec;

	buf_vec = sub_vec(point, &cone->b_disk_c);
	t = scalar_prod_vec(&buf_vec, &cone->vector);
	circle_center = mult_vec(&cone->vector, t);
	circle_center = add_vec(&cone->b_disk_c, &circle_center);
	factor = cone->height / cone->radius;
	normal_at_vec = sub_vec(point, &circle_center);
	normal_at_vec = mult_vec(&normal_at_vec, factor);
	normalize_vec(&normal_at_vec);
	return (normal_at_vec);
}

t_coordinates	normal_at_co(t_element *cone, t_coordinates *point)
{
	t_coordinates	normal_at_vec;

	if (cone->cam_intersec_type == 1)
		normal_at_vec = pyramid_normal(cone, point);
	if (cone->cam_intersec_type == 2)
		normal_at_vec = mult_vec(&cone->vector, -1);
	return (normal_at_vec);
}

static t_coordinates	pipe_normal(t_element *cylinder, t_coordinates *point)
{
	t_coordinates	buf_vec;
	double			t;
	t_coordinates	circle_center;
	t_coordinates	normal_at_vec;

	buf_vec = sub_vec(point, &cylinder->b_disk_c);
	t = scalar_prod_vec(&buf_vec, &cylinder->vector);
	circle_center = mult_vec(&cylinder->vector, t);
	circle_center = add_vec(&cylinder->b_disk_c, &circle_center);
	normal_at_vec = sub_vec(point, &circle_center);
	normalize_vec(&normal_at_vec);
	return (normal_at_vec);
}

t_coordinates	normal_at_cy(t_element *cylinder, t_coordinates *point)
{
	t_coordinates	normal_at_vec;

	if (cylinder->cam_intersec_type == 1)
		normal_at_vec = pipe_normal(cylinder, point);
	if (cylinder->cam_intersec_type == 2)
		normal_at_vec = cylinder->vector;
	if (cylinder->cam_intersec_type == 3)
		normal_at_vec = mult_vec(&cylinder->vector, -1);
	return (normal_at_vec);
}
