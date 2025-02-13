/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:21:37 by achantra          #+#    #+#             */
/*   Updated: 2025/02/13 13:38:21 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	debug_env_figure(t_element *figure)
{
	while (figure)
	{
		if (figure->id == CYLINDER)
			printf("cy %.2f,%.2f,%.2f %.2f,%.2f,%.2f %.2f %.2f %d,%d,%d\n",
				figure->coord->x, figure->coord->y, figure->coord->z,
				figure->vector->x, figure->vector->y, figure->vector->z,
				figure->diameter, figure->height,
				figure->color->r, figure->color->g, figure->color->b);
		else if (figure->id == SPHERE)
			printf("sp %.2f,%.2f,%.2f %.2f %d,%d,%d\n", figure->coord->x,
				figure->coord->y, figure->coord->z, figure->diameter,
				figure->color->r, figure->color->g, figure->color->b);
		else if (figure->id == PLANE)
			printf("pl %.2f,%.2f,%.2f %.2f,%.2f,%.2f %d,%d,%d\n",
				figure->coord->x, figure->coord->y, figure->coord->z,
				figure->vector->x, figure->vector->y, figure->vector->z,
				figure->color->r, figure->color->g, figure->color->b);
		figure = figure->next;
	}
}

void	debug_env(t_env *env)
{
	if (env->light)
		printf("L %.2f,%.2f,%.2f %.2f %d,%d,%d\n", env->light->coord->x,
			env->light->coord->y, env->light->coord->z, env->light->bright,
			env->light->color->r, env->light->color->g, env->light->color->b);
	if (env->amb)
		printf("A %.2f %d,%d,%d\n", env->amb->light, env->amb->color->r,
			env->amb->color->g, env->amb->color->b);
	if (env->camera)
		printf("C %.2f,%.2f,%.2f, %.2f,%.2f,%.2f, %.2f\n",
			env->camera->coord->x, env->camera->coord->y, env->camera->coord->z,
			env->camera->dir->x, env->camera->dir->y,
			env->camera->dir->z, env->camera->fov);
	if (env->figure)
		debug_env_figure(env->figure);
}
