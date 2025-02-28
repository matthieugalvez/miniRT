/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intsec_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:54:11 by achantra          #+#    #+#             */
/*   Updated: 2025/02/28 12:39:24 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"
#include "struct.h"

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
	t_coordinates	disk_pos;

	disk_pos = add_vec(*(co->coord), mult_vec(*(co->vector), co->height));
	inter = scalar_prod_vec(sub_vec(disk_pos, *(ray->origin)), *(co->vector))
		/ scalar_prod_vec(*(ray->direction), *(co->vector));
	point = add_vec(*(ray->origin), mult_vec(*(ray->direction), inter));
	if (scalar_prod_vec(sub_vec(point, disk_pos), sub_vec(point, disk_pos))
		< co->radius * co->radius)
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

static int	intersect_pyramid(t_element *co, double a, double b, double c)
{
	double			delta;

	delta = b * b - (4 * a * c);
	if (delta > EPSILON)
	{
		co->c_inter[0] = (-b + sqrt(delta)) / (2 * a);
		co->c_inter[1] = (-b - sqrt(delta)) / (2 * a);
		return (1);
	}
	return (0);
}

void	intersect_cone(t_element *co, t_ray *ray)
{
	double			tan_teta;
	t_coordinates	dis;
	double			a;
	double			b;
	double			c;

	tan_teta = 1
		+ (co->diameter / (2 * co->height)) * (co->diameter / (2 * co->height));
	dis = sub_vec(*ray->origin, *co->coord);
	a = scalar_prod_vec(*ray->direction, *ray->direction) - tan_teta
		* scalar_prod_vec(*ray->direction, *co->vector)
		* scalar_prod_vec(*ray->direction, *co->vector);
	b = 2 * (scalar_prod_vec(*ray->direction, dis) - tan_teta
			* scalar_prod_vec(*ray->direction, *co->vector)
			* scalar_prod_vec(dis, *co->vector));
	c = scalar_prod_vec(dis, dis) - tan_teta
		* (scalar_prod_vec(dis, *co->vector)
			* scalar_prod_vec(dis, *co->vector));
	if (intersect_pyramid(co, a, b, c))
	{
		get_z_loc_co(co, ray, &co->c_inter[0]);
		get_z_loc_co(co, ray, &co->c_inter[1]);
	}
	intersect_disk(co, ray);
}
