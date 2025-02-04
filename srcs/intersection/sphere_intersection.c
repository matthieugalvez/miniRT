/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:46:27 by achantra          #+#    #+#             */
/*   Updated: 2025/02/04 22:09:03 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	intersect_sphere(t_element *sp, t_ray *ray)
{
	t_coordinates	distance;
	double			discriminent;
	double			a;
	double			b;
	double			c;

	distance = substract_vec(*(ray->origin), *(sp->coord));
	a = scalar_prod_vec(*(ray->direction), *(ray->direction));
	b = 2.0 * scalar_prod_vec(*(ray->direction), distance);
	c = scalar_prod_vec(distance, distance) - (sp->diameter * sp->diameter) / 4;
	discriminent = b * b - 4 * a * c;
	if (discriminent >= 0 && ((-b - sqrt(discriminent)) / (2 * a) >= 0 || (-b
				+ sqrt(discriminent)) / (2 * a) >= 0))
		return (1);
	return (0);
}
