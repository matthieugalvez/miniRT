/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:42:37 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/20 11:49:12 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_ray(t_ray *ray, t_env *env, t_coordinates *hitpoint)
{
	t_coordinates	*origin;
	t_coordinates	*direction;

	direction = ft_calloc(sizeof(t_coordinates), 1);
	if (!direction)
		clean_env(env, 1);
	origin = env->light->coord;
	*direction = sub_vec(*hitpoint, *env->light->coord);
	normalize_vec(direction);
	ray->origin = origin;
	ray->direction = direction;
}
