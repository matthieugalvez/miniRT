/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:54:12 by mgalvez           #+#    #+#             */
/*   Updated: 2025/03/01 18:06:00 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_coordinates	normal_at_pl(t_element *plane, t_coordinates *point,
								t_ray *light_ray, t_ray *cam_ray)
{
	double	scalar_prod_light;
	double	scalar_prod_cam;

	scalar_prod_light = scalar_prod_vec(&light_ray->direction, &plane->vector);
	scalar_prod_cam = scalar_prod_vec(&cam_ray->direction, &plane->vector);
	if (scalar_prod_light * scalar_prod_cam >= 0)
	{
		if (scalar_prod_light > 0)
			return (mult_vec(&plane->vector, -1.0));
		else
			return (plane->vector);
	}
	return (light_ray->direction);
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

static t_coordinates	normal_at_cy(t_element *cylinder, t_coordinates *point)
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

static t_coordinates	normal_at_sp(t_element *sphere, t_coordinates *point)
{
	t_coordinates	normal_at_vec;

	normal_at_vec = sub_vec(point, &sphere->coord);
	normalize_vec(&normal_at_vec);
	return (normal_at_vec);
}

t_coordinates	get_normal_at(t_element *figure, t_coordinates *point,
							t_ray *light_ray, t_ray *cam_ray)
{
	if (figure->id == SPHERE)
		return (normal_at_sp(figure, point));
	if (figure->id == CYLINDER)
		return (normal_at_cy(figure, point));
	return (normal_at_pl(figure, point, light_ray, cam_ray));
}
