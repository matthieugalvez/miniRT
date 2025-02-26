/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intsec_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:54:11 by achantra          #+#    #+#             */
/*   Updated: 2025/02/26 13:48:05 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	intersect_disk_co(t_element *co, t_ray *ray)
{
	double			inter;
	t_coordinates	point;
	t_coordinates	disk_pos;

	disk_pos = add_vec(*(co->coord), mult_vec(*(co->vector), co->height));
	inter = scalar_prod_vec(sub_vec(disk_pos, *(ray->origin)), *(co->vector))
		/ scalar_prod_vec(*(ray->direction), *(co->vector));
	point = add_vec(*(ray->origin), mult_vec(*(ray->direction), inter));
	if (scalar_prod_vec(sub_vec(point, disk_pos), sub_vec(point,
				disk_pos)) < pow(co->diameter / 2, 2))
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

void	intersect_cone(t_element *co, t_ray *ray)
{
	double			a;
	double			b;
	double			c;
	double			delta;
	double			tan_teta;
	t_coordinates	dis;

	tan_teta = 1 + pow(co->diameter / (2 * co->height), 2);
	dis = sub_vec(*ray->origin, *co->coord);
	a = scalar_prod_vec(*ray->direction, *ray->direction) - tan_teta
		* scalar_prod_vec(*ray->direction, *co->vector)
		* scalar_prod_vec(*ray->direction, *co->vector);
	b = 2 * (scalar_prod_vec(*ray->direction, dis) - tan_teta
			* scalar_prod_vec(*ray->direction, *co->vector)
			* scalar_prod_vec(dis, *co->vector));
	c = scalar_prod_vec(dis, dis) - tan_teta * pow(scalar_prod_vec(dis,
				*co->vector), 2);
	delta = b * b - (4 * a * c);
	if (delta > 0 || equal_double(delta, 0))
	{
		co->c_inter[0] = (-b + sqrt(delta)) / (2 * a);
		get_z_loc_co(co, ray, &co->c_inter[0]);
		co->c_inter[1] = (-b - sqrt(delta)) / (2 * a);
		get_z_loc_co(co, ray, &co->c_inter[1]);
	}
	intersect_disk_co(co, ray);
}
