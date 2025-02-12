/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:46:27 by achantra          #+#    #+#             */
/*   Updated: 2025/02/12 18:46:14 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	intersect_sphere(t_env *env, t_element *sp, t_ray *ray)
{
	t_coordinates	distance;
	double			discriminent;
	double			a;
	double			b;

	distance = sub_vec(*(ray->origin), *(sp->coord));
	a = scalar_prod_vec(*(ray->direction), *(ray->direction));
	b = 2.0 * scalar_prod_vec(*(ray->direction), distance);
	discriminent = b * b - 4 * a * (scalar_prod_vec(distance, distance)
			- (sp->diameter * sp->diameter) / 4);
	if (discriminent >= 0)
	{
		sp->c_inter[0] = (-b - sqrt(discriminent)) / (2 * a);
		sp->c_inter[1] = (-b + sqrt(discriminent)) / (2 * a);
		return (1);
	}
	return (0);
}

static void	intersect_disk(t_element *cy, t_ray *ray, t_coordinates c_disk)
{
	double			inter;
	t_coordinates	point;

	inter = scalar_prod_vec(sub_vec(c_disk, *(ray->origin)),
			*(cy->vector)) / scalar_prod_vec(*(ray->direction), *(cy->vector));
	point = add_vec(*(ray->origin), mult_vec(*(ray->direction), inter));
	if (pow(norm_vec(sub_vec(point, c_disk)), 2) < pow(cy->diameter / 2, 2))
	{
		if (equal_double(cy->c_inter[0], __DBL_MAX__))
			cy->c_inter[0] = inter;
		else
			cy->c_inter[1] = inter;
	}
}

static void	choose_inter(t_element *cy, t_ray *ray,
						t_coordinates av, t_coordinates bv)
{
	double			a;
	double			b;
	double			c;
	double			z_loc;
	double			discriminent;

	a = scalar_prod_vec(av, av);
	b = 2 * scalar_prod_vec(av, bv);
	c = scalar_prod_vec(bv, bv) - ((cy->diameter * cy->diameter) / 4);
	discriminent = b * b - 4 * a * c;
	if (discriminent < 0)
		return ;
	cy->c_inter[0] = (-b - sqrt(discriminent)) / (2 * a);
	cy->c_inter[1] = (-b + sqrt(discriminent)) / (2 * a);
	z_loc = scalar_prod_vec(add_vec(*(ray->origin),
				sub_vec(mult_vec(*(ray->direction), cy->c_inter[0]),
					*(cy->coord))), *(cy->vector));
	if (z_loc < -cy->height / 2 || z_loc > cy->height / 2)
		cy->c_inter[0] = __DBL_MAX__;
	z_loc = scalar_prod_vec(add_vec(*(ray->origin),
				sub_vec(mult_vec(*(ray->direction), cy->c_inter[1]),
					*(cy->coord))), *(cy->vector));
	if (z_loc < -cy->height / 2 || z_loc > cy->height / 2)
		cy->c_inter[1] = __DBL_MAX__;
}

int	intersect_cylinder(t_env *env, t_element *cy, t_ray *ray)
{
	t_coordinates	distance;
	t_coordinates	av;
	t_coordinates	bv;

	distance = sub_vec(*(ray->origin), *(cy->coord));
	av = sub_vec(*(ray->direction), mult_vec(*(cy->vector),
				scalar_prod_vec(*(ray->direction), *(cy->vector))));
	bv = sub_vec(distance, mult_vec(*(cy->vector),
				scalar_prod_vec(distance, *(cy->vector))));
	cy->c_inter[0] = __DBL_MAX__;
	cy->c_inter[1] = __DBL_MAX__;
	choose_inter(cy, ray, av, bv);
	intersect_disk(cy, ray,
		add_vec(*(cy->coord), mult_vec(*(cy->vector), cy->height / 2)));
	intersect_disk(cy, ray,
		sub_vec(*(cy->coord), mult_vec(*(cy->vector), cy->height / 2)));
	if (equal_double(cy->c_inter[0], __DBL_MAX__)
		&& equal_double(cy->c_inter[1], __DBL_MAX__))
		ft_bzero(&cy->c_inter[0], sizeof(double) * 2);
	return (0);
}
