/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intsec_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:37:18 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/27 17:14:54 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	intersect_disk(t_element *cy, t_ray *ray,
				t_coordinates c_disk, int disk_case)
{
	double			inter;
	t_coordinates	point;
	double			norm;
	double			radius;

	inter = scalar_prod_vec(sub_vec(c_disk, *(ray->origin)),
			*(cy->vector)) / scalar_prod_vec(*(ray->direction), *(cy->vector));
	point = add_vec(*(ray->origin), mult_vec(*(ray->direction), inter));
	norm = get_norm(sub_vec(point, c_disk));
	radius = cy->diameter / 2;
	if (norm * norm < radius * radius)
	{
		if (equal_double(cy->c_inter[0], __DBL_MAX__))
		{
			cy->c_inter[0] = inter;
			if (cy->c_inter[0] <= cy->c_inter[1])
				cy->intersec_type = disk_case;
		}
		else
		{
			cy->c_inter[1] = inter;
			if (cy->c_inter[1] < cy->c_inter[0])
				cy->intersec_type = disk_case;
		}
	}
}

static void	get_z_loc(t_element *cy, t_ray *ray, double *intersection)
{
	double			z_loc;

	z_loc = scalar_prod_vec(add_vec(*(ray->origin),
				sub_vec(mult_vec(*(ray->direction), *intersection),
					*(cy->coord))), *(cy->vector));
	if (z_loc < -cy->height / 2 || z_loc > cy->height / 2)
		*intersection = __DBL_MAX__;
}

static void	intersect_pipe(t_element *cy, t_ray *ray,
						t_coordinates av, t_coordinates bv)
{
	double			a;
	double			b;
	double			c;
	double			z_loc;
	double			discriminant;

	a = scalar_prod_vec(av, av);
	b = 2 * scalar_prod_vec(av, bv);
	c = scalar_prod_vec(bv, bv) - ((cy->diameter * cy->diameter) / 4);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return ;
	cy->intersec_type = 1;
	cy->c_inter[0] = (-b - sqrt(discriminant)) / (2 * a);
	get_z_loc(cy, ray, &cy->c_inter[0]);
	cy->c_inter[1] = (-b + sqrt(discriminant)) / (2 * a);
	get_z_loc(cy, ray, &cy->c_inter[1]);
}

void	intersect_cylinder(t_element *cy, t_ray *ray)
{
	t_coordinates	distance;
	t_coordinates	av;
	t_coordinates	bv;
	t_coordinates	disk_vec;

	distance = sub_vec(*(ray->origin), *(cy->coord));
	av = sub_vec(*(ray->direction), mult_vec(*(cy->vector),
				scalar_prod_vec(*(ray->direction), *(cy->vector))));
	bv = sub_vec(distance, mult_vec(*(cy->vector),
				scalar_prod_vec(distance, *(cy->vector))));
	intersect_pipe(cy, ray, av, bv);
	disk_vec = add_vec(*(cy->coord), mult_vec(*(cy->vector), cy->height / 2));
	intersect_disk(cy, ray, disk_vec, 2);
	disk_vec = sub_vec(*(cy->coord), mult_vec(*(cy->vector), cy->height / 2));
	intersect_disk(cy, ray, disk_vec, 3);
}
