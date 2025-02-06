/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:46:27 by achantra          #+#    #+#             */
/*   Updated: 2025/02/06 16:04:34 by achantra         ###   ########.fr       */
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

int	intersect_cylinder(t_env *env, t_element *cy, t_ray *ray)
{
	t_coordinates distance;
	double discriminent;
	t_coordinates A;
	t_coordinates B;
	double a;
	double b;
	double c;
	double *root;
	double z_loc;

	distance = substract_vec(*(ray->origin), *(cy->coord));
	A = substract_vec(*(ray->direction), multiply_vec(*(cy->vector),
				scalar_prod_vec(*(ray->direction), *(cy->vector))));
	B = substract_vec(distance, multiply_vec(*(cy->vector),
				scalar_prod_vec(distance, *(cy->vector))));
	a = scalar_prod_vec(A, A);
	b = 2 * scalar_prod_vec(A, B);
	c = scalar_prod_vec(B, B) - ((cy->diameter * cy->diameter) / 4);
	discriminent = b * b - 4 * a * (scalar_prod_vec(distance, distance)
			- (cy->diameter * cy->diameter) / 4);
	if (discriminent >= 0)
	{
		root = malloc(sizeof(double) * 2);
		if (!root)
			return (perror("Error"), free(ray->direction), free(ray),
				clean_env_err(env), 0);
		root[0] = (-b - sqrt(discriminent)) / (2 * a);
		root[1] = (-b + sqrt(discriminent)) / (2 * a);
		z_loc = scalar_prod_vec(add_vec(*(ray->origin),
					substract_vec(multiply_vec(*(ray->direction), root[0]),
						*(cy->coord))), *(cy->vector));
		if (z_loc < -cy->height / 2 || z_loc > cy->height / 2)
			root[0] = __DBL_MAX__;
		z_loc = scalar_prod_vec(add_vec(*(ray->origin),
					substract_vec(multiply_vec(*(ray->direction), root[1]),
						*(cy->coord))), *(cy->vector));
		if (z_loc < -cy->height / 2 || z_loc > cy->height / 2)
			root[1] = __DBL_MAX__;
		cy->c_inter = root;
		return (1);
	}
	return (0);
}