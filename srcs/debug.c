/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:21:37 by achantra          #+#    #+#             */
/*   Updated: 2025/02/04 18:50:17 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	debug_env(t_env *env)
{
	t_element	*buf;

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
	if (env->elem)
	{
		buf = env->elem;
		while (buf)
		{
			if (buf->id == CYLINDER)
				printf("cy %.2f,%.2f,%.2f %.2f,%.2f,%.2f %.2f %.2f %d,%d,%d\n",
					buf->coord->x, buf->coord->y, buf->coord->z, buf->vector->x,
					buf->vector->y, buf->vector->z, buf->diameter, buf->height,
					buf->color->r, buf->color->g, buf->color->b);
			else if (buf->id == SPHERE)
				printf("sp %.2f,%.2f,%.2f %.2f %d,%d,%d\n", buf->coord->x,
					buf->coord->y, buf->coord->z, buf->diameter, buf->color->r,
					buf->color->g, buf->color->b);
			else if (buf->id == PLANE)
				printf("pl %.2f,%.2f,%.2f %.2f,%.2f,%.2f %d,%d,%d\n",
					buf->coord->x, buf->coord->y, buf->coord->z, buf->vector->x,
					buf->vector->y, buf->vector->z, buf->color->r,
					buf->color->g, buf->color->b);
			buf = buf->next;
		}
	}
}
