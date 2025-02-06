/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:46:27 by achantra          #+#    #+#             */
/*   Updated: 2025/02/06 13:37:02 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	intersect_sphere(t_env *env, t_element *sp, t_ray *ray)
{
	t_coordinates	distance;
	double			discriminent;
	double			a;
	double			b;
	double			*root;

	distance = substract_vec(*(ray->origin), *(sp->coord));
	a = scalar_prod_vec(*(ray->direction), *(ray->direction));
	b = 2.0 * scalar_prod_vec(*(ray->direction), distance);
	discriminent = b * b - 4 * a * (scalar_prod_vec(distance, distance)
			- (sp->diameter * sp->diameter) / 4);
	if (discriminent >= 0)
	{
		root = malloc(sizeof(double) * 2);
		if (!root)
			return (perror("Error"), free(ray->direction), free(ray),
				clean_env_err(env), 0);
		root[0] = (-b - sqrt(discriminent)) / (2 * a);
		root[1] = (-b + sqrt(discriminent)) / (2 * a);
		sp->c_inter = root;
		return (1);
	}
	return (0);
}
