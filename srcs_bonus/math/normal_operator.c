/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:54:12 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/27 17:38:04 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static t_coordinates	normal_at_pl(t_element *plane, t_coordinates *point,
								t_ray *light_ray, t_ray *cam_ray)
{
	double	scalar_prod_light;
	double	scalar_prod_cam;

	scalar_prod_light = scalar_prod_vec(*light_ray->direction, *plane->vector);
	scalar_prod_cam = scalar_prod_vec(*cam_ray->direction, *plane->vector);
	if (scalar_prod_light * scalar_prod_cam >= 0)
	{
		if (scalar_prod_light > 0)
			return (mult_vec(*plane->vector, -1.0));
		else
			return (*plane->vector);
	}
	return (*light_ray->direction);
}

static t_coordinates	normal_at_sp(t_element *sphere, t_coordinates *point)
{
	t_coordinates	normal_at_vec;

	normal_at_vec = sub_vec(*point, *sphere->coord);
	normalize_vec(&normal_at_vec);
	return (normal_at_vec);
}

t_coordinates	get_normal_at(t_element *figure, t_coordinates *point,
							t_ray *light_ray, t_ray *cam_ray)
{
	if (figure->id == SPHERE)
		return (normal_at_sp(figure, point));
	if (figure->id == CYLINDER)
		return (normal_at_cy(figure, point));
	if (figure->id == CONE)
		return (normal_at_co(figure, point));
	return (normal_at_pl(figure, point, light_ray, cam_ray));
}
