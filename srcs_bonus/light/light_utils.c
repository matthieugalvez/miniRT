/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:42:37 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/27 16:16:41 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	init_ray(t_ray *ray, t_env *env, t_hitpoint *hitpoint, t_light *light)
{
	t_coordinates	*origin;
	t_coordinates	*direction;

	direction = malloc(sizeof(t_coordinates));
	if (!direction)
	{
		free(hitpoint->coord);
		clean_env(env, 1);
	}
	origin = light->coord;
	*direction = sub_vec(*hitpoint->coord, *light->coord);
	normalize_vec(direction);
	ray->origin = origin;
	ray->direction = direction;
}
