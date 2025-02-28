/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intsec_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:54:11 by achantra          #+#    #+#             */
/*   Updated: 2025/02/28 16:30:06 by mgalvez          ###   ########.fr       */
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

static void	intersect_disk(t_element *co, t_ray *ray)
{
	double			inter;
	t_coordinates	point;
	t_coordinates	disk_vec;

	inter = scalar_prod_vec(sub_vec(co->b_disk_c, *(ray->origin)),
			*(co->vector)) / scalar_prod_vec(*(ray->direction), *(co->vector));
	point = add_vec(*(ray->origin), mult_vec(*(ray->direction), inter));
	disk_vec = sub_vec(point, co->b_disk_c);
	if (scalar_prod_vec(disk_vec, disk_vec) < co->radius * co->radius)
		set_intersec(co, inter);
}

static void	get_z_loc_co(t_element *co, t_ray *ray, double *intersection)
{
	double	z_loc;

	z_loc = scalar_prod_vec(add_vec(*(ray->origin),
				sub_vec(mult_vec(*(ray->direction), *intersection),
					*(co->coord))), *(co->vector));
	if (z_loc < 0 || z_loc > co->height)
		*intersection = __DBL_MAX__;
	else
		co->intersec_type = 1;
}

static int	intersect_pyramid(t_element *co, t_ray *ray,
				double tan_teta, t_coordinates dis)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	cos_angle;

	cos_angle = scalar_prod_vec(*ray->direction, *co->vector);
	a = scalar_prod_vec(*ray->direction, *ray->direction) - tan_teta
		* cos_angle * cos_angle;
	b = 2 * (scalar_prod_vec(*ray->direction, dis) - tan_teta
			* cos_angle * scalar_prod_vec(dis, *co->vector));
	cos_angle = scalar_prod_vec(dis, *co->vector);
	c = scalar_prod_vec(dis, dis) - tan_teta * cos_angle * cos_angle;
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
	double			tan_teta;
	t_coordinates	dis;

	tan_teta = 1
		+ (co->diameter / (2 * co->height)) * (co->diameter / (2 * co->height));
	dis = sub_vec(*ray->origin, *co->coord);
	if (intersect_pyramid(co, ray, tan_teta, dis))
	{
		get_z_loc_co(co, ray, &co->c_inter[0]);
		get_z_loc_co(co, ray, &co->c_inter[1]);
	}
	intersect_disk(co, ray);
}
