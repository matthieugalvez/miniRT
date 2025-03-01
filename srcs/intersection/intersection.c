/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:46:27 by achantra          #+#    #+#             */
/*   Updated: 2025/03/01 18:02:32 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	intersect_plane(t_element *pl, t_ray *ray)
{
	t_coordinates	dist_vec;
	double			t;

	if (equal_double(scalar_prod_vec(&pl->vector, &ray->direction), 0))
		return ;
	dist_vec = sub_vec(&ray->origin, &pl->coord);
	t = -scalar_prod_vec(&pl->vector, &dist_vec)
		/ scalar_prod_vec(&pl->vector, &ray->direction);
	pl->c_inter[0] = t;
}

static void	intersect_sphere(t_element *sp, t_ray *ray)
{
	t_coordinates	distance;
	double			discriminant;
	double			sqrt_discriminant;
	double			a;
	double			b;

	distance = sub_vec(&ray->origin, &sp->coord);
	a = scalar_prod_vec(&ray->direction, &ray->direction);
	b = 2.0 * scalar_prod_vec(&ray->direction, &distance);
	discriminant = b * b - 4 * a * (scalar_prod_vec(&distance, &distance)
			- (sp->diameter * sp->diameter) / 4);
	if (discriminant >= 0)
	{
		sqrt_discriminant = sqrt(discriminant);
		sp->c_inter[0] = (-b - sqrt_discriminant) / (2 * a);
		sp->c_inter[1] = (-b + sqrt_discriminant) / (2 * a);
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
	if (figure->c_inter[0] < intersec - EPSILON && figure->c_inter[0] > 0)
		intersec = figure->c_inter[0];
	if (figure->c_inter[1] < intersec - EPSILON && figure->c_inter[1] > 0)
		intersec = figure->c_inter[1];
	return (intersec);
}
