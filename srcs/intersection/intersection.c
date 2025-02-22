/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:46:27 by achantra          #+#    #+#             */
/*   Updated: 2025/02/22 14:40:20 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	intersect_plane(t_element *pl, t_ray *ray)
{
	double	denom;
	double	t;

	denom = scalar_prod_vec(*pl->vector, *ray->direction);
	if (equal_double(denom, 0))
		return ;
	if (denom > 0)
		pl->intersec_type = 1;
	t = scalar_prod_vec(sub_vec(*pl->coord, *ray->origin), *pl->vector);
	if (t >= 0)
		pl->c_inter[0] = t;
}

static void	intersect_sphere(t_element *sp, t_ray *ray)
{
	t_coordinates	distance;
	double			discriminant;
	double			a;
	double			b;

	distance = sub_vec(*(ray->origin), *(sp->coord));
	a = scalar_prod_vec(*(ray->direction), *(ray->direction));
	b = 2.0 * scalar_prod_vec(*(ray->direction), distance);
	discriminant = b * b - 4 * a * (scalar_prod_vec(distance, distance)
			- (sp->diameter * sp->diameter) / 4);
	if (discriminant >= 0)
	{
		sp->c_inter[0] = (-b - sqrt(discriminant)) / (2 * a);
		sp->c_inter[1] = (-b + sqrt(discriminant)) / (2 * a);
	}
}

double	find_intsec(t_ray *ray, t_element *figure)
{
	double	intersec;

	intersec = __DBL_MAX__;
	figure->c_inter[0] = __DBL_MAX__;
	figure->c_inter[1] = __DBL_MAX__;
	if (figure->id == SPHERE)
		intersect_sphere(figure, ray);
	else if (figure->id == CYLINDER)
		intersect_cylinder(figure, ray);
	else if (figure->id == PLANE)
		intersect_plane(figure, ray);
	if (!equal_double(figure->c_inter[0], intersec)
		&& figure->c_inter[0] < intersec && figure->c_inter[0] > 0)
		intersec = figure->c_inter[0];
	if (!equal_double(figure->c_inter[1], intersec)
		&& figure->c_inter[1] < intersec && figure->c_inter[1] > 0)
		intersec = figure->c_inter[1];
	return (intersec);
}
