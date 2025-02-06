/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:46:27 by achantra          #+#    #+#             */
/*   Updated: 2025/02/06 17:58:26 by achantra         ###   ########.fr       */
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
				clean_env_err(env), 1);
		root[0] = (-b - sqrt(discriminent)) / (2 * a);
		root[1] = (-b + sqrt(discriminent)) / (2 * a);
		sp->c_inter = root;
		return (1);
	}
	return (0);
}

void	intersect_disk(t_element *cy, t_ray *ray, double *root)
{
	t_coordinates	c_disk;
	double			inter;
	t_coordinates	point;

	c_disk = add_vec(*(cy->coord), multiply_vec(*(cy->vector), cy->height / 2));
	inter = scalar_prod_vec(substract_vec(c_disk, *(ray->origin)),
			*(cy->vector)) / scalar_prod_vec(*(ray->direction), *(cy->vector));
	point = add_vec(*(ray->origin), multiply_vec(*(ray->direction), inter));
	if (pow(norm_vec(substract_vec(point, c_disk)), 2) < pow(cy->diameter / 2,
			2))
	{
		if (equal_double(root[0], __DBL_MAX__))
			root[0] = inter;
		else
			root[1] = inter;
	}
	c_disk = substract_vec(*(cy->coord), multiply_vec(*(cy->vector), cy->height
				/ 2));
	inter = scalar_prod_vec(substract_vec(c_disk, *(ray->origin)),
			*(cy->vector)) / scalar_prod_vec(*(ray->direction), *(cy->vector));
	point = add_vec(*(ray->origin), multiply_vec(*(ray->direction), inter));
	if (pow(norm_vec(substract_vec(point, c_disk)), 2) < pow(cy->diameter / 2,
			2))
	{
		if (equal_double(root[0], __DBL_MAX__))
			root[0] = inter;
		else
			root[1] = inter;
	}
}

int	intersect_cylinder(t_env *env, t_element *cy, t_ray *ray)
{
	t_coordinates	distance;
	double			discriminent;
	t_coordinates	av;
	t_coordinates	bv;
	double			a;
	double			b;
	double			c;
	double			*root;
	double			z_loc;

	distance = substract_vec(*(ray->origin), *(cy->coord));
	av = substract_vec(*(ray->direction), multiply_vec(*(cy->vector),
				scalar_prod_vec(*(ray->direction), *(cy->vector))));
	bv = substract_vec(distance, multiply_vec(*(cy->vector),
				scalar_prod_vec(distance, *(cy->vector))));
	a = scalar_prod_vec(av, av);
	b = 2 * scalar_prod_vec(av, bv);
	c = scalar_prod_vec(bv, bv) - ((cy->diameter * cy->diameter) / 4);
	discriminent = b * b - 4 * a * c;
	root = malloc(sizeof(double) * 2);
	if (!root)
		return (perror("Error"), free(ray->direction), free(ray),
			clean_env_err(env), 1);
	root[0] = __DBL_MAX__;
	root[1] = __DBL_MAX__;
	if (discriminent >= 0)
	{
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
	}
	intersect_disk(cy, ray, root);
	if (equal_double(root[0], __DBL_MAX__) && equal_double(root[1],
			__DBL_MAX__))
	{
		free(root);
		root = NULL;
	}
	cy->c_inter = root;
	return (0);
}
