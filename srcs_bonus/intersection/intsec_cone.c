/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intsec_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:54:11 by achantra          #+#    #+#             */
/*   Updated: 2025/03/01 14:14:43 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	set_intersec(t_element *co, double inter)
{
	if (equal_double(co->c_inter[0], __DBL_MAX__))
	{
		co->c_inter[0] = inter;
		if (co->c_inter[0] < co->c_inter[1])
			co->intersec_type = 2;
	}
	else
	{
		co->c_inter[1] = inter;
		if (co->c_inter[1] < co->c_inter[0])
			co->intersec_type = 2;
	}
}

static void	intersect_disk(t_element *co, t_ray *ray, double cos_angle)
{
	t_coordinates	buf_vec;
	double			inter;
	t_coordinates	point;
	double			norm;

	buf_vec = sub_vec(&co->b_disk_c, &ray->origin);
	inter = scalar_prod_vec(&buf_vec, co->vector) / cos_angle;
	buf_vec = mult_vec(&ray->direction, inter);
	point = add_vec(&ray->origin, &buf_vec);
	buf_vec = sub_vec(&point, &co->b_disk_c);
	norm = get_norm(&buf_vec);
	if (norm * norm < co->radius * co->radius)
		set_intersec(co, inter);
}

static void	get_z_loc_co(t_element *co, t_ray *ray, double *intersection)
{
	t_coordinates	buf_vec;
	double			z_loc;

	buf_vec = mult_vec(&ray->direction, *intersection);
	buf_vec = sub_vec(&buf_vec, co->coord);
	buf_vec = add_vec(&ray->origin, &buf_vec);
	z_loc = scalar_prod_vec(&buf_vec, co->vector);
	if (z_loc < -co->height / 2 || z_loc > co->height / 2)
		*intersection = __DBL_MAX__;
	else
		co->intersec_type = 1;
}

static int	intersect_pyramid(t_element *co, t_ray *ray,
				double tan_teta, double cos_angle)
{
	t_coordinates	dis;
	double			a;
	double			b;
	double			c;
	double			delta;

	dis = sub_vec(&ray->origin, &co->t_disk_c);
	a = scalar_prod_vec(&ray->direction, &ray->direction) - tan_teta
		* cos_angle * cos_angle;
	b = 2 * (scalar_prod_vec(&ray->direction, &dis) - tan_teta
			* cos_angle * scalar_prod_vec(&dis, co->vector));
	cos_angle = scalar_prod_vec(&dis, co->vector);
	c = scalar_prod_vec(&dis, &dis) - tan_teta * cos_angle * cos_angle;
	delta = b * b - (4 * a * c);
	if (delta > EPSILON)
	{
		delta = sqrt(delta);
		a *= 2;
		co->c_inter[0] = (-b + delta) / a;
		co->c_inter[1] = (-b - delta) / a;
		return (1);
	}
	return (0);
}

void	intersect_cone(t_element *co, t_ray *ray)
{
	double			t;
	double			tan_teta;
	double			cos_angle;

	t = (co->diameter / (2 * co->height));
	tan_teta = 1 + t * t;
	cos_angle = scalar_prod_vec(&ray->direction, co->vector);
	if (intersect_pyramid(co, ray, tan_teta, cos_angle))
	{
		get_z_loc_co(co, ray, &co->c_inter[0]);
		get_z_loc_co(co, ray, &co->c_inter[1]);
	}
	intersect_disk(co, ray, cos_angle);
}
